class Solution {
public:
    int dp[200001];
    int cal(map<char,vector<int>>&mp, int i, int n,string &word){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        vector<int>&temp=mp[word[i]];
        int size=temp.size();
        int ind=lower_bound(temp.begin(),temp.end(),i+3)-temp.begin();
        if(ind!=size)ans=1+cal(mp,temp[ind],n,word);
        ans=max(ans,cal(mp,i+1,n,word));
        return dp[i]=ans;
    }
    int maxSubstrings(string word) {
        int n=word.size();
        map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[word[i]].push_back(i);
        }
        // for(auto it:mp){
        //     cout<<it.first<<" ->";
        //     for(auto it2:it.second)cout<<it2<<" ";
        //     cout<<endl;
        // }
        memset(dp,-1,sizeof(dp));
        return cal(mp,0,n,word);
        return 0;
    }
};