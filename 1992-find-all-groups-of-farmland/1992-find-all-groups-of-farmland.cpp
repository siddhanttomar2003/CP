class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    
     vector<vector<int>>ans;
     for(int i=0;i<land.size();i++){
        for(int j=0;j<land[i].size();j++){
            if(land[i][j]==1){
              
                int r=j;
                int d=i;
                while(r<land[i].size()){
                    if(land[i][r]){
                        r++;
                    }
                    else break;
                    
                }
                while(d<land.size()){
                    if(land[d][j]){
                       d++;
                    }
                    else break;
                }
                ans.push_back({i,j,d-1,r-1});
                for(int k=i;k<d;k++){
                    for(int l=j;l<r;l++){
                           land[k][l]=-1;
                    }
                }
               

                }
            }
        }
     return ans;

    
    }
};