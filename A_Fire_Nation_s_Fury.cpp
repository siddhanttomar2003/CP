#include <iostream>
#include <vector>
using namespace std;
 
const int MOD = 1000000007;
 
int n;
vector<vector<int>> graph;
vector<int> BIT;  // 1-indexed BIT array

// BIT update: add delta at position idx
void update(int idx, int delta) {
    while (idx <= n) {
        BIT[idx] += delta;
        idx += idx & -idx;
    }
}
 
// BIT query: sum of values in range [1, idx]
int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}
 
// DFS traversal: at each node, count active ancestors with label less than the node's label.
// 'parent' avoids revisiting the parent.
long long dfs(int node, int parent) {
    long long localSum = 0;
    // Count of ancestors with label < node
    int count = query(node - 1);
    localSum = (localSum + count) % MOD;
    
    // Mark current node as active (i.e. add it to the BIT)
    update(node, 1);
    
    // Process all children (neighbors except the parent)
    for (int child : graph[node]) {
        if (child != parent) {
            localSum = (localSum + dfs(child, node)) % MOD;
        }
    }
    
    // Remove current node from BIT as we backtrack
    update(node, -1);
    return localSum;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        graph.assign(n + 1, vector<int>());
        BIT.assign(n + 1, 0);
        
        // There are n-1 edges. Read the arrays A and B.
        vector<int> A(n - 1), B(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> B[i];
        }
        
        // Build the undirected tree.
        for (int i = 0; i < n - 1; i++) {
            int u = A[i], v = B[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        // Root the tree at node 1.
        long long totalJealousy = dfs(1, 0);
        cout << totalJealousy % MOD << "\n";
    }
    
    return 0;
}
