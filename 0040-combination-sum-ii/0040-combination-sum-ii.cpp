class Solution {
public:
     void recursion(vector<vector<int>>&ans,vector<int>&v,vector<int>&candidates,int target,int index){
         if(target==0){ans.push_back(v);return;}
         if(index==candidates.size()){
         if(target==0){
             ans.push_back(v);
         }
         return;
         }
         if(target<0)return;
         if(candidates[index]>target)return;
         v.push_back(candidates[index]);
         recursion(ans,v,candidates,target-candidates[index],index+1);
         v.pop_back();
         while(index+1<candidates.size()&&candidates[index+1]==candidates[index]){
             index++;
         }
         recursion(ans,v,candidates,target,index+1);
     
     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        sort(candidates.begin(),candidates.end());
        recursion(ans,v,candidates,target,index);
        
       return ans;

    }
};