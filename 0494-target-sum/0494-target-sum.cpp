class Solution {
public:
    int cal(map<pair<int,int>,int>&mp, int i, vector<int>&nums, int tar,int curr_sum){
        if(i==nums.size()){
           return curr_sum==tar;            
        }
        if(mp.find({i,curr_sum})!=mp.end())return mp[{i,curr_sum}];
        int w1=cal(mp,i+1,nums,tar,curr_sum+nums[i]);
        int w2=cal(mp,i+1,nums,tar,curr_sum-nums[i]);
        return mp[{i,curr_sum}]=w1+w2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        map<pair<int,int>,int>mp;
        return cal(mp,0,nums,target,0);

    }
};