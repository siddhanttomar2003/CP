#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	
	 int a[26];
	 for(int i=0;i<26;i++){
	     cin>>a[i];
	 }
    string s;
    cin>>s;
    int n=s.length();
    int hash[26]={0};
    for(int i=0;i<n;i++){
        hash[s[i]-97]++;
    }
    int ans=0;
    for(int i=0;i<26;i++){
        if(hash[i]==0){
            ans+=a[i];
        }
    }
    cout<<ans<<endl;
	}
	return 0;
}