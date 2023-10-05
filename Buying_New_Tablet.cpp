#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,b;
	    cin>>n>>b;
	    int arr[n][3];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<3;j++){
	            cin>>arr[i][j];
	        }
	    }
	    int ans=0;
	    int flag=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<3;j++){
	            if(j==2){
	                if(arr[i][2]<=b){
	                    ans=max(ans,arr[i][1]*arr[i][0]);
	                    flag=1;
	                }
	            }
	        }
	    }
	    if(flag==0) cout<<"no tablet"<<endl;
	    else cout<<ans<<endl;
	}
	return 0;
}
