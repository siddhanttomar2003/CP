class Solution {
public:
    int minOperations(int n) {
        vector<int>dis(2*n+1,1e9);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,n});
        while(pq.size()>0){
            auto it=pq.top();
            pq.pop();
            int num=it[1];
            int op=it[0];
            for(int i=0;i<20;i++){
                int newnum1=num+(1<<i);
                int newnum2=num-(1<<i);
                if(newnum1<=2*n && dis[newnum1]>1+op){
                    dis[newnum1]=1+op;
                    pq.push({dis[newnum1],newnum1});
                }
                if(newnum2>=0 && dis[newnum2]>1+op){
                    dis[newnum2]=1+op;
                    pq.push({dis[newnum2],newnum2});
                }
            }
        }
        return dis[0];
    }
};