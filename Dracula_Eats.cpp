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

          if(n%7>=2)cout<<n/7+1<<endl;
          else cout<<n/7<<endl;
	}
	return 0;
}