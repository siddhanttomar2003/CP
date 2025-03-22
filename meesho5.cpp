#include <bits/stdc++.h>
using namespace std;

/*
    Function to find the maximum possible S, where we can form
    2 groups of size S each (no enemies within the same group).
*/

static const int UNVISITED = 0;
static const int VISITED = 1;

vector<vector<int>> adj;    // adjacency list
vector<int> visited;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // Build adjacency list
    adj.assign(N+1, {});
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        // Undirected edge
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(N+1, UNVISITED);

    // We'll gather:
    //  1) sum0 = sum of all components that contribute difference = 0
    //  2) oddPaths = lengths of all path-components that yield difference = ±1
    long long sum0 = 0;            // total vertices from difference-0 components
    vector<long long> oddPaths;    // store lengths of odd path components

    // A function to BFS/DFS a connected component and figure out:
    //  - number of vertices (compV)
    //  - number of edges (compE) [count each edge once!]
    // Then classify path vs cycle, odd/even, etc.
    function<void(int)> bfsComponent = [&](int start){
        queue<int>q;
        q.push(start);
        visited[start] = VISITED;

        long long compV = 0;
        long long compE = 0;  // we'll count each edge once

        vector<int> nodesInComp; // store nodes for reference if needed
        while(!q.empty()){
            int u = q.front(); 
            q.pop();
            compV++;
            nodesInComp.push_back(u);
            for(auto &nx : adj[u]){
                compE++;  // but this counts each edge from u->nx
                if(!visited[nx]){
                    visited[nx] = VISITED;
                    q.push(nx);
                }
            }
        }
        // Each undirected edge was counted twice (u->v and v->u).
        compE /= 2;

        // Classify:
        // If compE == compV, it's a cycle
        // If compE == compV - 1, it's a path
        // (Given the problem statement, no other possibility if deg<=2)

        bool isCycle = (compE == compV); 
        // length = compV

        if(isCycle){
            // check odd or even
            if(compV % 2 == 0){
                // even cycle => difference=0, sum used = compV
                sum0 += compV;
            } else {
                // odd cycle => we remove 1 => difference=0, sum used = compV-1
                // or skip, but better to use compV-1 if compV>1
                if(compV > 1) sum0 += (compV - 1);
                // if compV=1, it's just a single node => path of length 1 anyway
                // but an odd cycle with compV=1 can't happen with edges=1, so skip that corner case
            }
        } else {
            // it's a path (or a single node, which is path of length=1)
            if(compV % 2 == 0){
                // even path => difference=0, sum=compV
                sum0 += compV;
            } else {
                // odd path => difference=±1, sum=compV
                oddPaths.push_back(compV);
            }
        }
    };

    // Traverse all components
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            bfsComponent(i);
        }
    }

    // Now we handle the oddPaths array.
    // Each odd path can be used with difference = +1 or -1, sum = length.
    // We want an even number of them so that half can be +1 and half can be -1
    // => total difference = 0.
    // So if we have k odd-path components, we want to pick the largest even subset by sum.
    // Strategy:
    //   - sum all lengths
    //   - if k is even, we can pick them all
    //   - if k is odd, we skip exactly one (the smallest) to make it an even count

    sort(oddPaths.begin(), oddPaths.end());
    long long sumOdd = 0;
    for(auto &val : oddPaths) sumOdd += val;

    if( (int)oddPaths.size() % 2 == 1 ){
        // remove the smallest to make the subset have even cardinality
        long long smallest = oddPaths[0];
        sumOdd -= smallest;
    }

    long long totalUsed = sum0 + sumOdd; 
    // totalUsed is how many students we can place into 2 groups with difference=0
    // => each group has totalUsed/2
    // S must be an integer, so totalUsed should be even. 
    // But in the worst case, totalUsed might be odd if everything was odd—but
    // given our logic, the difference=0 arrangement only works if totalUsed is even.
    // (The combination approach ensures totalUsed is indeed even.)
    
    long long S = totalUsed / 2;   // size of each group
    cout << S << "\n";

    return 0;
}
