#include<iostream>
using namespace std;


int main()
{
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    if(n%4==0){
        int a[n];
        for(int i=0;i<n/2;i++){
           a[i]=2*(i+1);
        }
        
    int j=0;
    for(int i=n/2;i<n;i++){
        if(i==n-1){
            a[i]=a[j]+j;
        }
        else{
        a[i]=a[j]-1;
        j++;
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    }
    else {cout<<"NO"<<endl;}
}
return 0;
}