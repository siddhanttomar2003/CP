#include <iostream>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	 int hash[101]={0};
	 int n;
	 cin>>n;
	 int a[n];
	 for(int i=0;i<n;i++){
	     cin>>a[i];
	     hash[a[i]]++;
	 }
	 bool flag=true;
	 for(int i=1;i<101;i++){
         if(hash[i]!=0&&hash[i]%2!=0){
             flag=false;
         } 	                                 
	}
	if(flag)cout<<"YES"<<endl;
	else cout<<" NO"<<endl;
	}
	return 0;
}