class Solution {
public:
      void recur(set<vector<int>>&s,int i,vector<int>&nums){
        if(i==nums.size()){
            s.insert(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            recur(s,i+1,nums);
            swap(nums[i],nums[j]);
        }
     }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>s;
        int i=0;
         recur(s,i,nums);
        vector<vector<int>>ans;
        for(auto it:s){
             ans.push_back(it);
        }
        return ans;
        
    }
};