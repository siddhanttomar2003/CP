class Solution {
public:
    int find_max(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i==grid.size()|| j==grid[0].size() || grid[i][j]==-1||grid[i][j]==0){
            return 0;
        }
        int take=grid[i][j];
         grid[i][j]=-1;
         int left= find_max(grid,i,j-1);
         int right=find_max(grid,i,j+1);
         int top = find_max(grid,i-1,j);
         int down =find_max(grid,i+1,j);
         grid[i][j]=take;
         return take+max(left,max(right,max(top,down)));

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0)
                ans=max(ans,find_max(grid,i,j));
            }
        }
        return ans;
    }
};