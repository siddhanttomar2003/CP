#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int res=0;
        int arr[10]={-1,1,2,3,4,5,6,7,8,9};
        int i=1;
        while(arr[i]<=n){
            res++;
            if(i==9){
                for(int j=1;j<=9;j++){
                    arr[j]*=10;
                }
                i=0;
            }
            i++;
        }

    cout<<res<<"\n";
    }
}