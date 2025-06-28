class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            int ind = lower_bound(matrix[i].begin(),matrix[i].end(), target) - matrix[i].begin();
            if(ind < m && matrix[i][ind] == target)return true;
        }
        return false;
    }
};