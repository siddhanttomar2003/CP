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
     int d[n];
     int s[n];
     for(int i=0;i<n;i++){
        cin>>d[i];
        cin>>s[i];
     }
     
     int ans=0;
     if(n==1){
        ans+=s[0]/2+d[0];
     }
     else{
     for(int i=1;i<n;i++){
     if(s[i-1]/2<d[i]-d[i-1]){
        ans=s[i-1]/2+d[i-1];
     }
     }
     }
     cout<<ans<<endl;

          	                                 
	}
	return 0;
}