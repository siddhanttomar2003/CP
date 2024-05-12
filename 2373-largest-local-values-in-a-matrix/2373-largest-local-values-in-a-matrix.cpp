class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>ans;
         for(int i=0;i<n-2;i++){
            vector<int>row;
            for(int j=0;j<n-2;j++){
                int maxi=INT_MIN;
                for(int k=i;k<min(i+3,n);k++){
                    for(int l=j;l<min(j+3,n);l++){
                        maxi=max(maxi,grid[k][l]);
                    }
                }
                row.push_back(maxi);
            }
            ans.push_back(row);
         }
         return ans;
      

    }
};