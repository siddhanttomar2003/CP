class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-1)==mp.end()&&mp.find(nums[i]+1)==mp.end()&&mp[nums[i]]==1){
               ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};