#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    const int NEG = -1000000000;
    int dp0 = NEG, dp1 = NEG;
    for(char c : s){
        if(c == '0')
            dp0 = max(dp0 + 1, max(dp1, 0));
        else
            dp1 = max(dp1 + 1, max(dp0, 0));
    }
    cout << max(dp0, dp1) << "\n";
}
    return 0;
}
