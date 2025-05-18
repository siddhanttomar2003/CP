class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(auto it:nums){
            if(mp.find(it)!=mp.end())continue;
            else {
                if(mp.find(it-1)!=mp.end())mp[it]=mp[it-1];
                if(mp.find(it+1)!=mp.end())mp[it]+=mp[it+1];
             // starting point of the chain
                mp[it]++;
                if(mp.find(it-1)!=mp.end()){
                mp[it-mp[it-1]]=mp[it];
                }
             // ending point of the chain 
             if(mp.find(it+1)!=mp.end()){
                mp[it+mp[it+1]]=mp[it];
             }
                ans=max(ans,mp[it]);
                
            }
        }
        return ans;
    }
};
