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
	 int sum=0;
	 for(int i=0;i<s.size();i++){
	     if((int)s[i]<=57&&(int)s[i]>=49){
	         sum+=s[i]-48;
	     }
	 }
	 cout<<sum<<endl;
          	                                 
	}
	return 0;
}