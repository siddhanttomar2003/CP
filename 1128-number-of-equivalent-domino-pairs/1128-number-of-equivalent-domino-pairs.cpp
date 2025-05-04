class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int>mp;
        for(auto it:dominoes){
            int mini=min(it[0],it[1]);
            int maxi=max(it[0],it[1]);
            mp[{mini,maxi}]++;
        }
        int ans=0;
        for(auto it:mp){
           int f=it.second;
           ans+=(f*(f-1))/2;
        }
        return ans;
    }
};