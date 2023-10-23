#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	 int p1,p2,k;
	 cin>>p1>>p2>>k;
	   int total=p1+p2;
	if((total/k+1)%2!=0)cout<<"CHEF"<<endl;
	else cout<<"COOK"<<endl;
          	                                 
	}
	return 0;
}