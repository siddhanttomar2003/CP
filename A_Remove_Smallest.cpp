#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	 int n;
     cin>>n;
     vector<int>v(n);
     for(int i=0;i<n;i++){
        cin>>v[i];
     }
     sort(v.begin(),v.end());
     int count=0;
     for(int i=0;i<n-1;i++){
        if(v[i+1]-v[i]<=1)count++;
     }
     if(count==n-1)cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
          	                                 
	}
	return 0;
}