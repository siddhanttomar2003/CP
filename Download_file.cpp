#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	 int n,k;
	 cin>>n>>k;
	 int t[n],d[n];
	   for(int i=0;i<n;i++){
	     cin>>t[i]>>d[i];
	                       }
	 int amount=0;                      
	 for(int i=0;i<n;i++){
	     if(k>=t[i]){
	         k-=t[i];
	     }
	     else {
	         amount+=(t[i]-k)*d[i];
	         k=0;
	     }
	 }
	 cout<<amount<<endl;
          	                                 
	}
	return 0;
}