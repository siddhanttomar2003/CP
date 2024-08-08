class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int total=rows*cols;
        vector<vector<int>>ans;
        int curr_x=rStart;
        int curr_y=cStart;
        int steps=1;
        int initial_dir=0;
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        while(ans.size()<total){
            int ori=steps;
             while(ori--){
                if(curr_x>=0 && curr_x<rows && curr_y>=0 && curr_y<cols)
                ans.push_back({curr_x,curr_y});
                curr_x+=dir[initial_dir].first;
                curr_y+=dir[initial_dir].second;
             }
             initial_dir=(initial_dir+1)%4;
             if(initial_dir==0 || initial_dir==2){
                steps++;
             }
        }
        return ans;

    }
};