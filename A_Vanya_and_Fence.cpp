#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

	    int n,h;
        cin>>n>>h;
        vector<int>v(n);
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]>h)ans+=2;
            else ans+=1;
        }
        cout<<ans<<endl;

	
	return 0;
}