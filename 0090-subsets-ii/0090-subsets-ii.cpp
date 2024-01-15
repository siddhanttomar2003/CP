class Solution {
public:
     void recursion(vector<vector<int>>&ans,vector<int>&v,vector<int>&nums,int index){
         if(index>=nums.size()){
             ans.push_back(v);
             return;
         }
         v.push_back(nums[index]);
         recursion(ans,v,nums,index+1);
         v.pop_back();
         while(index+1<nums.size()&&nums[index+1]==nums[index]){
               index++;
         }
         recursion(ans,v,nums,index+1);
     }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          //power set
          sort(nums.begin(),nums.end());
      int index=0;
      vector<vector<int>>ans;
      vector<int>v;
      recursion(ans,v,nums,index);
        return ans;
    }
};

     
    
