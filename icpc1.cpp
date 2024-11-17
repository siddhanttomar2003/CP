#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, d, l;
        cin >> n >> d >> l;
        if(d == 1){
            if(n == 2 && l == 2){
                cout << "1 2\n";
            }
            else{
                cout << "-1\n";
            }
        }
        else if(d == 2){
            if(l == n - 1 && n >= 3){
                string res = "";
                for(int i = 2; i <= n; i++) 
                    res += to_string(1) + " " + to_string(i) + "\n";
                cout << res;
            }
            else{
                cout << "-1\n";
            }
        }
        else{
            if((l >= 2 && l <= n - d + 1 && n >= d + 1)){
                if(l > 2 + (d - 1) * max(0LL, n - d - 1)){
                    cout << "-1\n";
                    continue;
                }
                vector<pair<int, int>> edg;

                for(int i = 1; i <= d; i++) 
                    edg.emplace_back(i, i + 1);

                int nxt = d + 1;
                queue<int> q;
                for(int i = 2; i <= d; i++) 
                    q.push(i);

                int remLeaf = l - 2;

                for(int i = 0; i < remLeaf && nxt < n; i++, nxt++){
                    if(q.empty()){
                        break;
                    }
                    int p = q.front();
                    edg.emplace_back(p, nxt + 1);
                    q.push(nxt + 1);
                }

                while(nxt < n){
                    if(q.empty()){
                        break;
                    }
                    int p = q.front();
                    q.pop();
                    edg.emplace_back(p, nxt + 1);
                    q.push(nxt + 1);
                    nxt++;
                }
                if(nxt != n){
                    cout << "-1\n";
                    continue;
                }

                vector<int> deg(n + 2, 0);
                for(auto &[u, v] : edg){
                    deg[u]++;
                    deg[v]++;
                }
                int lf = 0;
                for(int i = 1; i <= n; i++) 
                    if(deg[i] == 1) 
                        lf++;

                if(lf != l){
                    cout << "-1\n";
                    continue;
                }

                auto bfs = [&](int st) -> pair<int, int> {
                    vector<int> dist(n + 1, -1);
                    queue<int> qq;
                    qq.push(st);
                    dist[st] = 0;
                    int far = st;
                    while(!qq.empty()){
                        int u = qq.front(); 
                        qq.pop();
                        for(auto &[x, y] : edg){
                            if(x == u && dist[y] == -1){
                                dist[y] = dist[u] + 1;
                                qq.push(y);
                                if(dist[y] > dist[far]) 
                                    far = y;
                            }
                            else if(y == u && dist[x] == -1){
                                dist[x] = dist[u] + 1;
                                qq.push(x);
                                if(dist[x] > dist[far]) 
                                    far = x;
                            }
                        }
                    }
                    return {far, dist[far]};
                };
                
                pair<int, int> f1 = bfs(1);
                pair<int, int> f2 = bfs(f1.first);
                if(f2.second != d){
                    cout << "-1\n";
                    continue;
                }

                string res = "";
                for(auto &[u, v] : edg) 
                    res += to_string(u) + " " + to_string(v) + "\n";
                cout << res;
            }
            else{
                cout << "-1\n";
            }
        }
    }
}
