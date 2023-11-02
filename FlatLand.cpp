#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int count(int n){
    if(n<=0){
        return 0;
    }
    else {
        int i=1;
        int min=0;
        while(pow(i,2)<=n){
            min=i;
            i++;
        }
        return 1+count(n-(min*min));
    }
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	 cout<<count(n)<<endl;
          	                                 
	}
	return 0;
}