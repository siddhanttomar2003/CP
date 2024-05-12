class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
         vector<vector<int>>store_max1(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            int maxi=grid[i][n-1];
            for(int j=n-2;j>=0;j--){
               store_max1[i][j]=maxi;
               maxi=max(maxi,grid[i][j]);
            }
        }
        vector<vector<int>>store_maxi2(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            int maxi=grid[m-1][j];
            for(int i=m-2;i>=0;i--){
                store_maxi2[i][j]=maxi;
                maxi=max(maxi,grid[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<store_max1[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<store_maxi2[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
         vector<vector<int>>dp(m,vector<int>(n,0));
         for(int i=0;i<m;i++){
            dp[i][n-1]=store_maxi2[i][n-1];
         }
         for(int i=0;i<n;i++){
            dp[m-1][i]=store_max1[m-1][i];
         }
         for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
               dp[i][j]=max({store_max1[i][j],store_maxi2[i][j],dp[i+1][j],dp[i][j+1]});
            }
         }
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
         }
         cout<<endl;
         int final_ans=INT_MIN;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(i==m-1 && j==n-1)continue;
                final_ans=max(final_ans,dp[i][j]-grid[i][j]);
            }
         }
      return final_ans;
        
    }
};