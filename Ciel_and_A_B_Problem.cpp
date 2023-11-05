#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
     int a,b;
     cin>>a>>b;
     int ans=a-b;
      if(ans%10!=9)cout<<ans+1;
      else cout<<ans-1;
	return 0;
}