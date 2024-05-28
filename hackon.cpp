#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to perform DFS and compute the required weight increases
pair<int, int> dfs(int node, int N, const vector<int>& W) {
    if (node >= (1 << N)) {
        // If the node is a leaf, return (distance, increase) as (0, 0)
        return {0, 0};
    }

    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    // Recursively calculate for left and right children
    auto left = dfs(left_child, N, W);
    auto right = dfs(right_child, N, W);

    // Calculate the edge weights for the current node
    int left_edge_weight = W[left_child - 2];
    int right_edge_weight = W[right_child - 2];

    // Calculate the current distances to the deepest leaf in both subtrees
    int left_distance = left.first + left_edge_weight;
    int right_distance = right.first + right_edge_weight;

    // Calculate the increase needed to equalize the paths
    int increase_needed = abs(left_distance - right_distance);

    // Accumulate the total increase needed
    int total_increase = left.second + right.second + increase_needed;

    // Return the max distance from this node to its leaves and the total increase
    return {max(left_distance, right_distance), total_increase};
}

int main() {
    int N;
    cin >> N;

    int num_edges = (1 << (N + 1)) - 2;
    vector<int> W(num_edges);

    for (int i = 0; i < N-1; ++i) {
        cin >> W[i];
    }

    // Start DFS from the root node (node 1)
    auto result = dfs(1, N, W);

    // Output the total increase needed
    cout << result.second << endl;

    return 0;
}
