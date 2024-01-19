class Solution {
public:
     void recursion(int index ,int &max_index, int ar[],int target,vector<int>&v,vector<vector<int>>&ans){
         if(index==9){
             if(target==0&&v.size()==max_index){
                 ans.push_back(v);
                 return;
             }
             return;
         }
         if(target<0){
             return;
         }
         v.push_back(ar[index]);
          recursion(index+1,max_index,ar,target-ar[index],v,ans);
          v.pop_back();
          recursion(index+1,max_index,ar,target,v,ans);
     }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        int target=n;
        int index=0;
        int max_index=k;
          int ar[9];
        for(int i=0;i<9;i++){
           ar[i]=i+1;      
        }
        recursion(index,max_index,ar,target,v,ans);
        return ans;
    }
};