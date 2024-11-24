class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int count_neg=0;
        long long maxi= 1e6;
        bool check=false;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    check=true;
                }
                if(matrix[i][j]<0){
                    count_neg++;
                }
                maxi=min(maxi,abs(matrix[i][j])*1ll);
                ans+=(abs(matrix[i][j]));
            }
        }
        if(check)return ans;
        if(count_neg&1){
            ans-=(2*maxi);
        }
        return ans;
    }
};