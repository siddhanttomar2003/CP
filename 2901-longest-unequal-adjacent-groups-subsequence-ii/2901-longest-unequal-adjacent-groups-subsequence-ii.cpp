class Solution {
public:
    bool check(string &a, string &b, int c, int d){
        if(a.size() != b.size()) return false;
        int co = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) co++;
        }
        return co == 1 && c != d;
    }

    int cal(vector<int>& v, int i, int last, vector<vector<int>>& dp, vector<vector<bool>>& isOk, vector<vector<int>>& nextIdx){
        if(i == v.size()) return 0;
        if(dp[i][last + 1] != -1) return dp[i][last + 1];

        int take = 0;
        if(last == -1 || isOk[v[i]][v[last]]) {
            take = 1 + cal(v, i + 1, i, dp, isOk, nextIdx);
        }
        int skip = cal(v, i + 1, last, dp, isOk, nextIdx);

        if(take > skip) {
            nextIdx[i][last + 1] = 1; 
            dp[i][last + 1] = take;
        } else {
            nextIdx[i][last + 1] = 0; 
            dp[i][last + 1] = skip;
        }
        return dp[i][last + 1];
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        map<int, vector<int>> mp;
        int n = words.size();
        for(int i = 0; i < n; i++){
            mp[words[i].size()].push_back(i);
        }

        int maxLen = 1;
        vector<string> bestSubseq;

        vector<vector<bool>> isOk(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(check(words[i], words[j], groups[i], groups[j])){
                    isOk[i][j] = true;
                    isOk[j][i] = true;
                }
            }
        }

        for(auto& it : mp){
            vector<int>& temp = it.second;
            int s = temp.size();

            vector<vector<int>> dp(s, vector<int>(s + 1, -1));
            vector<vector<int>> nextIdx(s, vector<int>(s + 1, -1)); 
            int len = cal(temp, 0, -1, dp, isOk, nextIdx);
            if(len > maxLen){
                maxLen = len;
                bestSubseq.clear();
                int i = 0, last = -1;
                while(i < s){
                    if(nextIdx[i][last + 1] == 1){
                        bestSubseq.push_back(words[temp[i]]);
                        last = i;
                    }
                    i++;
                }
            }
        }
        if(maxLen == 1)return {words[0]};
        return bestSubseq;
    }
};
