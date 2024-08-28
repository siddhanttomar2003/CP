#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> temp(n * n + 1, -1);  // Initialize 1D board with -1
        
        // Flatten the board into 1D with handling of snaking left and right
        int idx = 1;  // Start at position 1
        bool leftToRight = true;  // Track direction of traversal
        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    temp[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    temp[idx++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;  // Toggle direction
        }
        
        // Use BFS to find the shortest path to the end
        queue<pair<int, int>> q;  // {position, steps}
        vector<int> dist(n * n + 1, INT_MAX);
        dist[1] = 0;  // Start at square 1
        q.push({1, 0});
        
        while (!q.empty()) {
            int pos = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            // Check if reached the last square
            if (pos == n * n) return steps;
            
            // Explore the next 6 positions (dice roll)
            for (int i = 1; i <= 6; i++) {
                int nextPos = pos + i;
                if (nextPos > n * n) continue;  // Out of bounds
                
                // If there's a ladder or snake, move to that position
                if (temp[nextPos] != -1) {
                    nextPos = temp[nextPos];
                }
                
                // If this position hasn't been visited in fewer steps
                if (dist[nextPos] == INT_MAX) {
                    dist[nextPos] = steps + 1;
                    q.push({nextPos, steps + 1});
                }
            }
        }
        
        return -1;  // No way to reach the last square
    }
};
