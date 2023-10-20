#include <iostream>
#include<bits/stdc++.h>
#include<vector>
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
	   
	 int count=0;
	 for(int i=0;i<n;i++){
	     if(v[i]==v[i+1]&&i<n-1){
	         count++;
	         i++;
	     }
	     else count++;
	 }
	 cout<<count<<endl;
	    
	    
	    
	}
	return 0;
}
