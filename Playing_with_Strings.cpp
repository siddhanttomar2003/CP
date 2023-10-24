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
string s,r;
cin>>s>>r;
int sum1=0;
int sum2=0;
for(int i=0;i<n;i++){
    sum1+=s[i];
    sum2+=r[i];
}
if(sum1==sum2)cout<<"YES"<<endl;
else cout<< "NO"<<endl;
	}
	return 0;
}