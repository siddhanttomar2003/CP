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
	    string s;
	    cin>>s;
	    int c0=0;
	    int c1=0;
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='0') c0++;
	        else c1++;
	    }
	    if(c1>c0)ans=c0+1;
	    else ans=c1;
	    cout<<ans<<endl;
	}
	return 0;
}
