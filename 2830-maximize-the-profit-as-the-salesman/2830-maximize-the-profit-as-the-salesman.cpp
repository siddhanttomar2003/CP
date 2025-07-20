class Solution {
public:
    int dp[100001];
    int cal(vector<vector<int>>&o, vector<int>&s, int i, int n){
        if(i >= n)return 0;
        if(dp[i] != -1)return dp[i];
        int p = 0;
        int end = o[i][1];
        int ind = upper_bound(s.begin(), s.end(), end) - s.begin();
        cout << ind << " ";
        p = max(p, o[i][2] + cal(o, s, ind, n));
        p = max(p, cal(o, s, i + 1, n));
        return dp[i] = p;
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        vector<int>start;
        for(auto it : offers){
            start.push_back(it[0]);
        }
        // for(int i = 0; i < start.size(); i++)cout << start[i] << " ";
        // cout << endl;
        n = start.size();
        memset(dp, -1, sizeof(dp));
        return cal(offers, start, 0, n);
        // return 0;
    }
};