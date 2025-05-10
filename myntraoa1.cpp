#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    static int f[500][500];
    const int MINF = -1000000000;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            f[i][j] = MINF;

    int ans = 0;
    for(int k = 0; k < n; k++){
        f[k][k] = a[k];
        ans = max(ans, a[k]);
    }

    for(int t = 0; t < n; t++){
        for(int i = 0; i < t; i++){
            int S = f[i][t];
            if(S < 0) continue;
            for(int j = t + 1; j < n; j++){
                if(a[j] <= a[i]){
                    f[j][t] = max(f[j][t], S + a[j]);
                    ans = max(ans, f[j][t]);
                }
                if(a[j] >= a[t]){
                    f[i][j] = max(f[i][j], S + a[j]);
                    ans = max(ans, f[i][j]);
                }
            }
        }
        for(int k2 = 0; k2 <= t; k2++){
            int S = f[t][k2];
            if(S < 0) continue;
            for(int j = t + 1; j < n; j++){
                if(a[j] <= a[t]){
                    f[j][k2] = max(f[j][k2], S + a[j]);
                    ans = max(ans, f[j][k2]);
                }
                if(a[j] >= a[k2]){
                    f[t][j] = max(f[t][j], S + a[j]);
                    ans = max(ans, f[t][j]);
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
