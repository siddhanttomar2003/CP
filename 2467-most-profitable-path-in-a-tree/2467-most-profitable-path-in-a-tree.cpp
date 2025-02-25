class Solution {
public:
    void dfs(int a, int b,vector<vector<int>>&adj, map<int,int>&par_child,map<int,int>&child_par,vector<int>&vis){
        if(a==b)return;
        vis[a]=1;
        for(int i=0;i<adj[a].size();i++){
             int child=adj[a][i];
             if(!vis[child]){
             child_par[child]=a;
             dfs(child,b,adj,par_child,child_par,vis);
             }
        }
    }
    void dfs2(int s, vector<vector<int>>&adj,vector<int>&vis,vector<int>&amounts,int curr, int &maxi){
        vis[s]=1;
        bool check=false;
        for(int i=0;i<adj[s].size();i++){
            int child=adj[s][i];
            if(!vis[child]){
                check=true;
               dfs2(child,adj,vis,amounts,curr+amounts[s],maxi);
            }
        }
        if(!check && adj[s].size()==1){
            maxi=max(maxi,curr+amounts[s]);
            return;
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        map<int,int>par_child;
        map<int,int>child_par;
        vector<int>vis(n+1,0);
        dfs(0,bob,adj,par_child,child_par,vis);
        int b=bob;
        while(b!=0){
            par_child[child_par[b]]=b;
            b=child_par[b];
        }
        int a=0;
        vector<int>vis3(n+1,0);
        // cout<<par_child[a]<<" "<<child_par[bob]<<endl;
        amount[bob]=0;
        while(par_child[a]!=child_par[bob] && !vis3[a] && !vis3[bob]){
            vis3[a]=1;
            vis3[bob]=1;
            amount[bob]=0;
            bob=child_par[bob];
            if(bob==a)break;
            a=par_child[a];
        }
        if(par_child[a]==child_par[bob]){
            int node=par_child[a];
            amount[node]/=2;
        }
        for(int i=0;i<amount.size();i++)cout<<amount[i]<<" ";
        cout<<"\n";
        vector<int>vis2(n+1,0);
        int maxi=-1e9;
        dfs2(0,adj,vis2,amount,0,maxi);
        return maxi;
    }
};