class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int>mp;
        for(auto it:answers){
            mp[it+1]++;
        }
        int ans=0;
        for(auto it:mp){
           int times=it.second/it.first+(it.second%it.first==0?0:1);
           ans+=it.first*times;
        }
        return ans;
    }
};