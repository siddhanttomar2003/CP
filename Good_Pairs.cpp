#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int x,y;
	    cin>>x;
	    unordered_map<int,int>mp;
         for(int i=0;i<x;i++)	 {
             cin>>y;
             mp[y]++;
         }  
         long long ans=0;
         for(auto a:mp){
             int f=a.second;
             
             ans=ans+ (long long) f*(f-1)/2;
         }
         cout<<ans<<endl;
	}
	return 0;
}