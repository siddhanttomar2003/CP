#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	 
          	  int n,x,y;
          	  cin>>n>>x>>y;
          	  vector<int>v(y*2);
          	  for(int i=0;i<y*2;i++){
          	      cin>>v[i];
          	  }
          	  for(int i=0;i<y*2;i+=2){
          	     if(v[i]==x||v[i+1]==x){
          	         if(v[i]==x)x=v[i+1];
          	         else x=v[i];
          	         
          	     } 
          	  }
          	  cout<<x<<endl;
	}
	return 0;
}
