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
	 int count0=0;
	 int count1=0;
	 for(int i=0;i<n;i++){
	     cin>>v[i];
	     if(v[i]==0)count0++;
	     else count1++;
	 }
	 
	 
	     if(count0%2!=0)cout<<"NO"<<endl;
	     else cout<<"YES"<<endl;

	     
	 
          	                                 
	}
	return 0;
}