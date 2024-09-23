class Solution {
public:
    int cal(string s, int i , map<string,int> & mp, vector<int>&dp){
        if(i==s.size()){  
           return 0 ;
        }
        int mini=INT_MAX;
        for(int j=i;j<s.size();j++){
            string temp=s.substr(i,j-i+1);
            if(mp.find(temp)!=mp.end()){
              mini = min(mini,cal(s,j+1,mp,dp));
            }
            else {
               mini =min(mini, j-i+1+cal(s,j+1,mp,dp));
            }
        }
        return dp[i]=mini;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int ans=s.size();
        map<string,int>mp;
        for(int i=0;i<dictionary.size();i++){
           mp [dictionary[i]]++;
        }
        int n=s.size();
        vector<int>dp(n,-1);
        cal(s,0,mp,dp);
        return dp[0];
    }
};