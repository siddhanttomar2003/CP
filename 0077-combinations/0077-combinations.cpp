class Solution {
public:

    void create(vector<vector<int>> &ans,vector<int> &v,int i,int n,int k){
        if(k==0){
            ans.push_back(v);
            return;
        }
        if(i==n+1)return;
        v.push_back(i);
        create(ans,v,i+1,n,k-1);
        v.pop_back();
        create(ans,v,i+1,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
         vector<int>v;
         create(ans,v,1,n,k);
         return ans;
    }
};