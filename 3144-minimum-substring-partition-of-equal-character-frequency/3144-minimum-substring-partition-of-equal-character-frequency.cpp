class Solution {
public:
    bool possible(unordered_map<char,int> &mp){
        int count=0;
        int prev;
        for(auto it:mp){
            if(count==0){
                prev=it.second;
                count++;
            }
            else if(it.second!=prev)return false;
        }
        return true;
    }
    
    int find_ways(int i , string &s,vector<int> &dp){
        if(i==s.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        unordered_map<char,int>mp;
        int n=s.length();
        int count=INT_MAX;
        for(int j=i;j<s.length();j++){
            mp[s[j]]++;
            if(possible(mp)){
             count=min(count,1+find_ways(j+1,s,dp));
            }
        }
        return dp[i]=count;
        
    }
    int minimumSubstringsInPartition(string s) {
        // using recursion
        int n=s.length();
        vector<int>dp(n,-1);
        return find_ways(0,s,dp);

    
     
    }
};