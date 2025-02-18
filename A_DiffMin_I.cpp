#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            ans=min(ans,arr[i+1]-arr[i]);
        }
        cout<<ans<<endl;
    }

}