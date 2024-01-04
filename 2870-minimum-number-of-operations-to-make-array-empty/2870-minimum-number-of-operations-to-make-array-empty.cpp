class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minop=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second==1)return -1;
            if(it.second%3==0)minop+=it.second/3;
            else minop+=it.second/3+1;
        }
        return minop;
    }
};