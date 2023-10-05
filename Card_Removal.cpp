#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    sort(v.begin(),v.end());
	    int ans=0;
	    int count=0;
	 for(int i=0;i<n-1;i++)
	 {
	     	        
	    if(v[i]==v[i+1]){
	        count++;
	    }
	    else{

	        count=0;
	    }
	    ans=max(ans,count);
	 }
	   cout<<n-(ans+1)<<endl;  
	     
	 
	    
	
	}
	return 0;
}
