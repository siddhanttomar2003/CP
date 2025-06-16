class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int curr=0;
        if(grid[0][0]!=0)return false;
        map<int,pair<int,int>>mp;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]={i,j};
            }
        }
        while(curr<n*n-1){
            int next=curr+1;
            int curr_x=mp[curr].first;
            int curr_y=mp[curr].second;
            int next_x=mp[next].first;
            int next_y=mp[next].second;
            int del_x=abs(curr_x-next_x);
            int del_y=abs(curr_y-next_y);
            if(del_x*del_y!=2)return false;
            curr++;
        }
        return true;
    }
};