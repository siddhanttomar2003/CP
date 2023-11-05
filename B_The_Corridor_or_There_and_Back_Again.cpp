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
          long long d[n],s[n];
          for(int i=0;i<n;i++){
            cin>>d[i]>>s[i];
          }	  
          long long k=INT64_MAX;
            for(int i=0;i<n;i++){
              k=min(d[i]+(s[i]-1)/2,k);
            }  
            cout<<k<<endl;                             
	}
	return 0;
}