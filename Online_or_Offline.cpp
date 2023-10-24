#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	 float n,m;
	 cin>>n>>m;
n=n-(n*10)/100;
if(n<m)cout<<"ONLINE"<<endl;
else if(n==m)cout<<"EITHER"<<endl;
else cout<<"DINING"<<endl;

          	                                 
	}
	return 0;
}