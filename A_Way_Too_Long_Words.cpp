#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    string s;
        cin>>s;
        if(s.size()<=10) cout <<s<<endl ;
        else{
        int count=0;
        for(int i=1;i<s.size()-1;i++){
            count++;
        }
        cout<<s[0]<<count<<s[s.size()-1]<<endl;
	}
    }
	return 0;
}