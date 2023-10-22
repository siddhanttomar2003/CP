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
	 string s;
	 cin>>s;
	 vector<int>v;
	 for(int i=0;i<n;i++){
	     v.push_back((int)s[i]);
	 }
	 sort(v.begin(),v.end());
	 int flag=0;
	 for(int i=0;i<n-1;i++){
	     if(v[i]==v[i+1]){
	         flag=1;
	         cout<<n-2<<endl;
	         break;
	     }
	 }
	 if(flag==0)cout<<-1<<endl;
          	                                 
	}
	return 0;
}