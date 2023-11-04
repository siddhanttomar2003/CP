#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	 
         int n,x;
         cin>>n>>x;
         int a[n];
         for(int i=0;i<n;i++){
             cin>>a[i];
         }
       if(n==1){
           if(a[0]<x)cout<<"-1"<<endl;
           else cout<<a[0]/x<<endl;
       }
       else{
       int sum=0;
       int m=INT_MAX;
       for(int i=0;i<n;i++){
           if(a[i]<m)m=a[i];
           sum+=a[i];
       }
          if(sum/x==(sum-m)/x)cout<<"-1"<<endl;
          else cout<<sum/x<<endl;
           
       }
	}  
         
          
	
	return 0;
}