class Solution {
public:
    void cal(vector<int>&c,vector<vector<int>>&ans,vector<int>&curr,int i,int tar){
        if(i==c.size()){
            if(tar==0)ans.push_back(curr);
            return;
        }
        if(c[i]<=tar){
            curr.push_back(c[i]);
            cal(c,ans,curr,i+1,tar-c[i]);
            curr.pop_back();
        }
        while(i+1<c.size() && c[i]==c[i+1])i++;
        cal(c,ans,curr,i+1,tar);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int tar) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(c.begin(),c.end());
        cal(c,ans,curr,0,tar);
        return ans;
    }
};
