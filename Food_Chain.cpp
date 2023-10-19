#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int e,k;
	    cin>>e>>k;
	    int count=0;
	    int n=e/k;
	    while(n>0){
	        count++;
	        n/=k;
	        
	    }
	    cout<<count+1<<endl;
	}
	return 0;
}
