#include <bits/stdc++.h>
using namespace std;

bool check(long long c, vector<long long >&arr){
    long long curr=c;
    long long count=0;
    long long last_min=1e12;
    for(int i=0;i<arr.size();i++){
        curr+=arr[i];
        last_min=min(last_min,arr[i]);
        if(curr<0){
            curr-=last_min;
            count++;
        }
    }
    return count<=1;
}
int main(){
    int testcases;
    cin>>testcases;
    while(testcases--){
        int n;
        cin>>n;
        vector<long long>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        long long l=0;
        long long h=1e18;
        long long ans=h;
        while(l<=h){
            long long m=l+(h-l)/(2*1ll);
            if(check(m,arr)){
                 ans=m;
                 h=m-1;
            }
            else l=m+1;
        }
        cout<<ans<<endl;
    }
}