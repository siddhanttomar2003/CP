#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        set<pair<int, int>> stampedCells;
        int currX = 0, currY = 0;

        for (int i = 0; i < n; ++i) {
            int moveX, moveY;
            cin >> moveX >> moveY;
            currX += moveX;
            currY += moveY;

            for (int dx = 0; dx < m; ++dx) {
                for (int dy = 0; dy < m; ++dy) {
                    stampedCells.insert({currX + dx, currY + dy});
                }
            }
        }

        int perimeter = 0;
        for (const auto& cell : stampedCells) {
            int x = cell.first, y = cell.second;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (stampedCells.find({nx, ny}) == stampedCells.end()) {
                    ++perimeter;
                }
            }
        }

        cout << perimeter << endl;
    }

    return 0;
}
