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
	    int ans=0;
	    int count=0;
	    for(int i=0;i<n-1;i++){
	        for(int j=i+1;j<n;j++){
	            if(v[i]==v[j]){
	                count++;
	            }
	        }
	        ans=max(ans,count);
	        count=0;
	    }
	    cout<<n-(ans+1)<<endl;
	}
	return 0;
}
