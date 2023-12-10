class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int k=matrix.size();
        int l=matrix[0].size();
        vector<vector<int>>v(l,vector<int>(k));
        for(int i=0;i<k;i++){
            for(int j=0;j<l;j++){
                v[j][i]=matrix[i][j];
            }
        }
        return v;
    }
};