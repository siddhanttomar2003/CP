class Solution {
public:

     void cal(vector<int> &candidates, int tar, int i,vector<int> &temp,vector<vector<int>>&ans){
        if(tar==0){ 
            ans.push_back(temp);
            return ;
        }
        if(i==candidates.size()){
            return;
        }
        if(candidates[i]<=tar){
            temp.push_back(candidates[i]);
            cal(candidates,tar-candidates[i],i+1,temp,ans);
            temp.pop_back();
        }
         while(  i+1<candidates.size() && candidates[i]==candidates[i+1] ){
            i++;
         }
           cal(candidates,tar,i+1,temp,ans);

     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        cal(candidates,target,0,temp,ans);
        return ans;
    }
};