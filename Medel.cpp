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
	 int a[n];
	 for(int i=0;i<n;i++){
	     cin>>a[i];
	 }
	 int mini=INT_MAX;
	 int maxi=INT_MIN;
	 int posmin=-1;
	 int posmax=-1;
	 for(int i=0;i<n;i++){
	     if(a[i]<mini){
	         mini=a[i];
	         posmin=i;
	     }
	     if(a[i]>maxi){
	         maxi=a[i];
	         posmax=i;
	     }
	 }
	 if(posmax<posmin)cout<<maxi<<" "<<mini<<endl;
	 else cout<<mini<<" "<<maxi<<endl;
          	                                 
	}
	return 0;
}