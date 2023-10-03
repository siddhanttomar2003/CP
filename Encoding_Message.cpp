#include <iostream>
#include<bits/stdc++.h>
#include<string>
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
	    int check=0;
	   for(int i=0;i<n;i++){
	       if(i%2==0&&i<n-1){
	           swap(s[i],s[i+1]);
	       }
	   }
	   for(int i=0;i<n;i++){
	       check='z'-s[i]+'a';
	      
	       s[i]=check;
	       
	       }
	       cout<<s;
	       cout<<endl;
	       
	   
	   
	    
	   
	}
	return 0;
}
