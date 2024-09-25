// soln:-1
// def solution(schedules, length):
//     m = sorted([m for e in schedules for m in e])
//     e = 0
//     for s, f in m:
//         if e + length <= s:
//             return e
//         e = max(e, f)
//     return e if e + length <= 24 * 60 else -1
// soln:-2
// #include <vector>
// #include <iostream>
// using namespace std;
// vector<vector<char>> gravityEffect(vector<vector<char>>& matrix) {
//     int rows = matrix.size();
//     int cols = matrix[0].size();
//         vector<pair<int, int>> figureCells;
//     for (int r = 0; r < rows; ++r) {
//         for (int c = 0; c < cols; ++c) {
//             if (matrix[r][c] == 'F') {
//                 figureCells.push_back({r, c});
//             }
//         }
//     }

//     int maxFallDistance = rows;
//     for (auto& cell : figureCells) {
//         int r = cell.first;
//         int c = cell.second;
//                 int fallDistance = 0;
//         for (int rr = r + 1; rr < rows; ++rr) {
//             if (matrix[rr][c] == '-' || matrix[rr][c] == 'F') {
//                 fallDistance++;
//             } else {
//                 break;
//             }
//         }
        
//         maxFallDistance = min(maxFallDistance, fallDistance);
//     }

//     for (auto& cell : figureCells) {
//         matrix[cell.first][cell.second] = '-';
//     }
//         for (auto& cell : figureCells) {
//         int newRow = cell.first + maxFallDistance;
//         matrix[newRow][cell.second] = 'F';
//     }

//     return matrix;
// }
// soln:-3
// void solve(vector<int>&v)
// {
//     int n=v.size();
//     map<int,vector<int>>mv;
//     for(int i=0;i<n;i++)
//     {
//         int num=v[i];
//         int ct=0;
//         while(num)
//         {
//             ct++;
//             num/=10;
//         }
//         mv[ct].push_back(v[i]);
//     }
//     int ct=0;
//     for(auto &ele:mv)
//     {
//         map<int,int>hash;
//         for(auto &it:ele.second)
//         {
//             hash[it]++;
//         }
//         int len=ele.first;
//         for(auto &it:hash)
//         {
//             ct+=(it.second*(it.second-1))/2;
//             for(int i=0;i<len;i++)
//             {
//                 for(int j=i+1;j<len;j++)
//                 {
//                     string temp=to_string(it.first);
//                     if(temp[i]!=temp[j])
//                     {
//                         swap(temp[i],temp[j]);
//                         int num=stoi(temp);
//                         if(hash.find(num)!=hash.end())
//                         {
//                             ct+=hash[num];
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     cout<<ct/2<<'\n';
// }
// soln:-5
// def solution(a, b):
//     def iDigit(s1, s2, i):
//         d1 = int(s1[-i]) if i <= len(s1) else 0
//         d2 = int(s2[-i]) if i <= len(s2) else 0
//         return d1 + d2

//     result = []
//     maxL = max(len(a), len(b))
    
//     for i in range(1, maxL + 1):
//         result.append(str(iDigit(a, b, i)))
    
//     return ''.join(result[::-1])
soln:-6
def go(bubbles, col, row):
    m = len(bubbles)
    row = min(row, m - 1)
    t = row
    for i in range(row, -1, -1):
        if bubbles[i][col] != 0:
            bubbles[t][col] = bubbles[i][col]
            t -= 1
    for t in range(t, -1, -1):
        bubbles[t][col] = 0

def solution(bubbles, operations):
    m, n = len(bubbles), len(bubbles[0])
    dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]
    for operation in operations:
        x, y = operation[0], operation[1]
        if x < 0 or x >= m or y < 0 or y >= n or bubbles[x][y] == 0:
            continue
        c = 0
        color = bubbles[x][y]
        for d in range(4):
            xx, yy = x + dx[d], y + dy[d]
            if 0 <= xx < m and 0 <= yy < n and bubbles[xx][yy] == color:
                c += 1
        if c < 2:
            continue
        bubbles[x][y] = 0
        for d in range(4):
            xx, yy = x + dx[d], y + dy[d]
            if 0 <= xx < m and 0 <= yy < n and bubbles[xx][yy] == color:
                bubbles[xx][yy] = 0
                if yy != y:
                    go(bubbles, yy, x)
        go(bubbles, y, x + 1)

def print_bubbles(bubbles):
    for bubble in bubbles:
        for x in bubble:
            print(x, end=" ")
        print()
    print()
// soln:-7 
// vector<int> solution(vector<vector<int>> matrix) {
//     int n = matrix.size();
//     vector<vector<int>> v(n, vector<int>(2, 0));

//     for (int i = 0; i < n; i++) {
//         v[i][1] = matrix[i][0];
//         int row = i, col = 0;
//         while (row >= 0 && col < n) 
//             v[i][0] += matrix[row--][col++];
//             row=1;
 
//         while (row < n && col < n) {
//             v[i][0] += matrix[row++][col++];
//         }
// }

//     sort(v.begin(), v.end());

//     vector<int> ans(n);
//     for (int i = 0; i < n; i++) {
//         ans[i] = v[i][1];
//     }

//     return ans;
// }

// int main() {
//     vector<vector<int>> matrix1 = {
//         {2, 3, 2},
//         {0, 2, 5},
//         {1, 0, 1}
//     };
//     vector<int> result1 = solution(matrix1);

//     for (int val : result1) {
//         cout << val << " ";
//     }
//     cout << endl; 

//     vector<vector<int>> matrix2 = {
//         {1, 3, 2, 5},
//         {3, 2, 5, 0},
//         {9, 0, 1, 3},
//         {6, 1, 0, 8}
//     };
//     vector<int> result2 = solution(matrix2);
//     for (int val : result2) {
//         cout << val << " ";
//     }
//     cout << endl; 

//     return 0;
// }

