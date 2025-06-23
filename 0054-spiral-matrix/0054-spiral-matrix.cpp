class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans;
        int s_r = 0 , e_r = n - 1;
        int s_c = 0 , e_c = m - 1;
        while(s_r <= e_r || s_c <= e_c){
            for(int i = s_c ; i <= e_c ; i++){
                ans.push_back(matrix[s_r][i]);
            }
            s_r++;
            for(int i = s_r ; i <= e_r ; i++){
                ans.push_back(matrix[i][e_c]);
            }
            e_c--;
            if(s_r <= e_r){
            for(int i = e_c ; i >= s_c ; i--){
                ans.push_back(matrix[e_r][i]);
            }
            e_r --;
            }
            if(s_c <= e_c){
            for(int i = e_r ; i >= s_r ; i--){
                ans.push_back(matrix[i][s_c]);
            }
            s_c++;
            }
        }
        return ans;
    }
};