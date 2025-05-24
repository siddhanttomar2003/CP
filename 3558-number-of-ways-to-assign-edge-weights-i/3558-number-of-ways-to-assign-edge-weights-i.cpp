
class Solution {
public:
    typedef long long ll;
    const ll m=1e9+7;
    vector<ll>fac,inv;
    ll modulo_expo(ll a, ll b){
        ll res=1;
        while(b>0){
            if(b&1){
                res=(res*a)%m;
            }
            a=(a*a)%m;
            b>>=(1*1ll);
        }
        return res;
    }
    void cal(int n){
        fac.resize(n+1,0);
        inv.resize(n+1,0);
        fac[0]=1;
        for(ll i=1;i<=n;i++){
            fac[i]=(fac[i-1]*i)%m;
        }
        inv[n]=modulo_expo(fac[n],m-2);
        for(ll i=n-1;i>=0;i--){
            inv[i]=(inv[i+1]*(i+1))%m;
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int e=edges.size();
        vector<vector<int>>adj(e+2);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int len=0;
        queue<vector<int>>q;
        vector<int>vis(e+2,0);
        q.push({0,1});
        vis[1]=1;
        while(q.size()>0){
            int par=q.front()[1];
            int curr_len=q.front()[0];
            q.pop();
            len=max(len,curr_len);
            for(auto it:adj[par]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({curr_len+1,it});
                }
            }
        }
        ll ways=0;
        cout<<len<<endl;
        cal(len);
        for(int i=1;i<=len;i+=2){
            ways= (ways+(((fac[len]*inv[i])%m)*(inv[len-i]))%m)%m;
        }
        return ways;
    }
};