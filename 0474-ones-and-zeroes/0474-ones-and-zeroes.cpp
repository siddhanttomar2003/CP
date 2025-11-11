class Solution {
public:
    int dp[601][101][101];
    int cal(vector<pair<int, int>>&temp, int i, int m, int n, int s){
        if(i == temp.size()){
            return 0;
        }
        if(dp[i][m][n] != -1)return dp[i][m][n];
        int ans = 0;
        if(temp[i].first <= m && temp[i].second <= n){
            ans = 1 + cal(temp, i + 1, m - temp[i].first, n - temp[i].second, s);
        }
        ans = max(ans, cal(temp, i + 1, m, n, s));
        return dp[i][m][n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>>temp;
        int size = strs.size();
        for(auto &it : strs){
            int count_zero = 0;
            int count_one = 0;
            for(auto &it2 : it){
                if(it2 == '0')count_zero++;
                else count_one++;
            }
            temp.push_back({count_zero, count_one});
        }
        // for(int i = 0; i < size; i++){
        //     cout << temp[i].first << " " << temp[i].second << endl;
        // }
        memset(dp, -1, sizeof(dp));
        return cal(temp, 0, m, n, size);
    }
};