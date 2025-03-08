class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        int n=grid.size();
        int size=n*n;
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
             ans.push_back(grid[i][j]);
          }
        }
        int missing=0;
        vector<int>f;
        int dup=0;
        for(int i=0;i<size;i++){
            if(ans[i]!=i+1){
                 if(ans[i]==ans[ans[i]-1]){
                    dup=ans[i];
                 }
                 else {
                    swap(ans[i],ans[ans[i]-1]);
                    i--;
                 }  
            }
        }
        for(int i=0;i<size;i++){
            if(ans[i]!=i+1)missing=i+1;
        }
        f.push_back(dup);
        f.push_back(missing);
        return f;
    }
};