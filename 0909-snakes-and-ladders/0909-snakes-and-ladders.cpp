class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        map<int,int>mp;
        int n=board.size();
        vector<int>temp(n*n+1);
        int m=board[0].size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                  if((n-1-i)%2==0){
                       temp[(n-1-i)*n+(j+1)]=board[i][j];
                  }
                  else {
                    temp[(n-1-i)*n+(m-j)]=board[i][j];
                  }
                 
            }
        }

        queue<pair<int,int>>q;
        vector<int>dis(n*n+1,INT_MAX);
        dis[1]=0;
        q.push({1,0});
        while(q.size()>0){
            int par=q.front().first;
            int times=q.front().second;
            q.pop();
            for(int i=0;i<=6;i++){
                if(par+i<=n*n && dis[par+i]>times+1){
                    dis[par+i]=times+1;
                    if(temp[par+i]!=-1){
                        dis[temp[par+i]]=times+1;
                        q.push({temp[par+i],times+1});
                    }
                    else {
                    q.push({par+i,times+1});
                    }
                }
            }
        }
        if(dis[n*n]==INT_MAX)return -1;
        return dis[n*n];
    }
};