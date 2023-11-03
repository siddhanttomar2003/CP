#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	 string s;
	 cin>>s;
	 int n=s.length();
	 int count=0;
	 for(int i=0;i<n-1;i++){
	     if(s[i]=='x'&&s[i+1]=='y'){
	         count++;
	         i=i+1;
	     }
	    else  if(s[i]=='y'&&s[i+1]=='x'){
	         count++;
	         i=i+1;
	     }
	 }
	 cout<<count<<endl;
          	                                 
	}
	return 0;
}