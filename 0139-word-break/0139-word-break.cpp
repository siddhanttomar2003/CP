class Solution {
public:
    int dp[301];
    int cal(string &s, unordered_map<string,int>&mp, int i){
        if(i==s.size())return true;
        if(dp[i]!=-1)return dp[i];
        int isPos=false;
        for(int j=i;j<s.size();j++){
            if(mp.find(s.substr(i,j-i+1))!=mp.end()){
                 isPos|=cal(s,mp,j+1);
            }
        }
        return dp[i]=isPos;
    }
    bool wordBreak(string s, vector<string>& w) {
        unordered_map<string,int>mp;
        for(auto it:w){
            mp[it]++;
        }
        memset(dp,-1,sizeof(dp));
        return cal(s,mp,0);
    }
};