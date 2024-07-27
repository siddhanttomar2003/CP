class Solution {
public:
    class Dsu{
        public:
        vector<int>parent;
        vector<int>rank;
        Dsu(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findparent(int node){
            if(parent[node]==node){
                    return node;
            }
            else return parent[node]=findparent(parent[node]);
        }
        void unions(int u, int v){
            u=findparent(u);
            v=findparent(v);
            if(u==v)return ;
            else if(rank[u]>rank[v]){
                parent[v]=u;
            }
            else if(rank[v]>rank[u]){
                parent[u]=v;
            }
            else {
                parent[u]=v;
                rank[v]++;
            }
        }


    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int>mp;
        int n=accounts.size();
        Dsu d(n);
         for(int i=0;i<n;i++){
           for(int j=1;j<accounts[i].size();j++){
            if(mp.find(accounts[i][j])==mp.end()){
               mp[accounts[i][j]]=i;
            }
            else {
                d.unions(i,mp[accounts[i][j]]);
              int par=  d.findparent(i);
              mp[accounts[i][j]]=i;
                
            }
           }
         }
         vector<vector<string>>ans(n);
         for(auto it:mp){
            int child=it.second;
           int par= d.findparent(child);
           ans[par].push_back(it.first);
         }
         for(int i=0;i<n;i++){
                // cout<<ans[i][j]<<" ";
                reverse(ans[i].begin(),ans[i].end());
                ans[i].push_back(accounts[i][0]);
                reverse(ans[i].begin(),ans[i].end());
            
            // cout<<endl;
         }
        vector<vector<string>>f_ans;
        for(int i=0;i<n;i++){
            if(ans[i].size()>1){
                f_ans.push_back(ans[i]);
            }
        }
        return f_ans;
         


    }
};