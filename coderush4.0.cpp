#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <stack>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> findMinWeightCycles(int N, int M, vector<int>& startNodes, vector<int>& endNodes, vector<int>& weights) {
    vector<vector<pair<int, int>>> adj(N);

    // Build the adjacency list
    for (int i = 0; i < M; i++) {
        int u = startNodes[i] - 1; // convert to zero-based index
        int v = endNodes[i] - 1;   // convert to zero-based index
        adj[u].emplace_back(v, weights[i]);
    }

    vector<int> min_cycle_weight(N, INF);

    for (int i = 0; i < N; i++) {
        vector<bool> visited(N, false);
        vector<bool> in_stack(N, false);
        vector<int> path_weight(N, 0);
        stack<int> st;
        bool found_cycle = false;
        int cycle_weight = INF;

        st.push(i);
        while (!st.empty()) {
            int node = st.top();
            if (!visited[node]) {
                visited[node] = true;
                in_stack[node] = true;
            } else {
                in_stack[node] = false;
                st.pop();
                continue;
            }

            for (auto& edge : adj[node]) {
                int neighbor = edge.first;
                int edge_weight = edge.second;

                if (!visited[neighbor]) {
                    path_weight[neighbor] = path_weight[node] + edge_weight;
                    st.push(neighbor);
                } else if (in_stack[neighbor]) {
                    cycle_weight = min(cycle_weight, path_weight[node] + edge_weight - path_weight[neighbor]);
                    found_cycle = true;
                }
            }
        }

        if (found_cycle) {
            min_cycle_weight[i] = cycle_weight;
        } else {
            min_cycle_weight[i] = -1;
        }
    }

    // Check for self-loops separately
    for (int i = 0; i < M; i++) {
        int u = startNodes[i] - 1;
        int v = endNodes[i] - 1;
        if (u == v) {
            if (min_cycle_weight[u] == -1 || min_cycle_weight[u] > weights[i]) {
                min_cycle_weight[u] = weights[i];
            }
        }
    }

    return min_cycle_weight;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> startNodes(M), endNodes(M), weights(M);
    for (int i = 0; i < M; i++) {
        cin >> startNodes[i] >> endNodes[i] >> weights[i];
    }

    vector<int> result = findMinWeightCycles(N, M, startNodes, endNodes, weights);

    for (int weight : result) {
        cout << weight << " ";
    }

    return 0;
}
