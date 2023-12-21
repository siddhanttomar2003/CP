class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<vector<int>>v;
        map<int,vector<int>>mp;
        for(int i=0;i<mat.size();i++){
         for(int j=0;j<mat[i].size();j++){
             mp[i+j].push_back(mat[i][j]);
         }
        }
        int count=0;
        for(auto it:mp){
            if(it.first%2==0){
              reverse(it.second.begin(),it.second.end());
              v.push_back(it.second);
            }
            else v.push_back(it.second);
        }
        vector<int>ans;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                ans.push_back(v[i][j]);
            }
        }
        return ans;
    }
};