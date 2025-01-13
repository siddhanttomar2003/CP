#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

int n;
int arr[500005];

bool check(int k){
    for(int i=1;i<=k;i++){
        if(arr[i]*2>arr[n-k+i]){
            return false;
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    int low=0,high=n/2;
    while(low!=high){
        int mid = (low+high+1)/2;
        if(check(mid)){
            low = mid;
        }
        else{
            high = mid-1;
        }
    }
    cout << low << "\n";
    return 0;
}