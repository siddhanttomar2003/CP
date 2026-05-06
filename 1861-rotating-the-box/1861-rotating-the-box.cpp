class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& b) {
        int n = b.size(), m = b[0].size();
        vector<vector<char>>ans(m, vector<char>(n, '.'));
        for(int i = 0; i < n; i++){
            queue<int>q;
            for(int j = m - 1; j >= 0; j--){
                if(b[i][j] == '.')q.push(j);
                else if(b[i][j] == '*'){
                    while(q.size())q.pop();
                    ans[j][n - i - 1] = '*';
                }
                else {
                    b[i][j] = '.';
                    q.push(j);
                    ans[q.front()][n - i - 1] = '#';
                    q.pop();
                }
            }
        }
        return ans;
    }
};