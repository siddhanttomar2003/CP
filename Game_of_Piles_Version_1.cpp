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
	 int flag=1;
	 int sum=0;
	 for(int i=0;i<n;i++){
	    if(a[i]==1){flag=0;break;}
	    sum+=a[i];
	    
	 }
	 if(flag==0)cout<<"CHEF"<<endl;
	 else 
	 if(sum%2!=0)
	 cout<<"CHEF"<<endl;
	 else cout<<"CHEFINA"<<endl;
          	                                 
	}
	return 0;
}