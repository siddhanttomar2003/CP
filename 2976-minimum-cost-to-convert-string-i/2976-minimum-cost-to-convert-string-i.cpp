class Solution {
public:
     void cal(int start,vector<vector<pair<int,int>>> &adj, vector<long long> &dis ){
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        dis[start]=0;
        pq.push({0,start});
        while(pq.size()>0){
            int par=pq.top().second;
            long long wt=pq.top().first;
            pq.pop();
            for(int i=0;i<adj[par].size();i++){
                int child=adj[par][i].first;
                int cost=adj[par][i].second;
                if(dis[child]>dis[par]+cost){
                    dis[child]=dis[par]+cost;
                    pq.push({dis[child],child});
                }
            }
        }
     }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>>adj(26);
        for(int i=0;i<original.size();i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            int wt=cost[i];
            adj[u].push_back({v,wt});
        }
        // vector<int>dis(26,1e9);
        vector<vector<long long>>t_dis(26);
        for(int i=0;i<26;i++){
            vector<long long> dis(26,1e9);
            cal(i,adj,dis);
            t_dis[i]=dis;
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            int index_s=source[i]-'a';
            int index_tar=target[i]-'a';
            if(t_dis[index_s][index_tar]==1e9)return -1;
            else ans+=t_dis[index_s][index_tar];
        }
        return ans;



    }
};