class Solution {
public:
    int dp[301][28][28];
    int cal(int i, int f, int s, string & w, map<int, vector<int>>&mp){
        if(i == w.size())return 0;
        if(dp[i][f + 1][s + 1] != -1)return dp[i][f + 1][s + 1];
        int steps = 1e9;
        int curr = w[i] - 65;
        if(f == -1){
            steps = min(steps, cal(i + 1, curr, s, w, mp));
        }
        else {
            int delx1 = abs(mp[f][1] - mp[curr][1]);
            int dely1 = abs(mp[f][0] - mp[curr][0]);
            steps = min(steps, delx1 + dely1 + cal(i + 1, curr, s, w, mp));
        }
        if(s == -1){
            steps = min(steps, cal(i + 1, f, curr, w, mp));
        }
        else {
            int delx2 = abs(mp[s][1] - mp[curr][1]);
            int dely2 = abs(mp[s][0] - mp[curr][0]);
            steps = min(steps, delx2 + dely2 + cal(i + 1, f, curr, w, mp));
        }
        return dp[i][f + 1][s + 1] = steps;
    }
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        map<int, vector<int>>mp;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 6; j++){
                int num = i * 6 + j;
                mp[num] = {i, j};
            }
        }
        // for(auto it : mp){
        //     cout << it.first << " ->" << it.second[0] << " " << it.second[1] << endl;
        // }
        return cal(0, -1, -1, word, mp);
    }
};