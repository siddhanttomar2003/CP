#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	ll k,n; cin>>k>>n;
	string a[k],b[n];
	for(int i=0; i<k; i++) cin>>a[i];
	for(int i=0; i<n; i++) cin>>b[i];
	//checking each element in the array b 
	for(int i=0; i<n; i++){
	    //getting each comparison element from array a
	    int check = 1;
	    for(int j=0; j<k; j++){
	        if(b[i].find(a[j]) != std::string::npos)
	        {
	            cout<<"Good\n"; check = 0; break;
	        }
	    }
	        if(check){
	            if(b[i].length() >= 47) cout<<"Good\n";
	            else cout<<"Bad\n";
	        }
	}
	
	return 0;
}