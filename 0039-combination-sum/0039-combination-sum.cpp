class Solution {
public:
     void recursion(vector<int>&v,vector<int>&candidates,int target,int i,vector<vector<int>>&ans){
         if(i==candidates.size()){
         if(target==0){
            ans.push_back(v);
         }
         return;
         }
         if(target<0)return;
         v.push_back(candidates[i]);
         recursion(v,candidates,target-candidates[i],i,ans);
         v.pop_back();
         recursion(v,candidates,target,i+1,ans);
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>>ans;
       int i=0;
       vector<int>v;
       recursion(v,candidates,target,i,ans);
       return ans;
    }
};