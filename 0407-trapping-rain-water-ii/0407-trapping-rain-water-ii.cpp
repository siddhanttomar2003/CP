class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        vector<vector<int>>contri(n,vector<int>(m,0));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][m-1],i,m-1});
            contri[i][0]=1;
            contri[i][m-1]=1;
        }
        for(int i=1;i<m-1;i++){
          pq.push({heightMap[0][i],0,i});
          pq.push({heightMap[n-1][i],n-1,i});
          contri[0][i]=1;
          contri[n-1][i]=1;
        }
        int ans=0;
        int level=0;
        while(pq.size()>0){
             level=max(level,pq.top()[0]);
            int curr_r=pq.top()[1];
            int curr_c=pq.top()[2];
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            pq.pop();
            for(int i=0;i<4;i++){
                int n_r=curr_r+delRow[i];
                int n_c=curr_c+delCol[i];
                if(n_r<n && n_r>=0 && n_c<m && n_c>=0 && !contri[n_r][n_c] ){
                    contri[n_r][n_c]=1;
                    ans+=(max(0,level-heightMap[n_r][n_c]));
                    pq.push({max(level,heightMap[n_r][n_c]),n_r,n_c});
                }
            }
        }
        return ans;
    }
};