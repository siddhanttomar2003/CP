#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int seats=0;
	    if(m%2==0)seats=m/2;
	    else seats=m/2+1;
	    
	    int rows=0;
	    if(n%2==0)rows=n/2;
	    else rows=n/2+1;
	    cout<<rows*seats<<endl;
	}
	return 0;
}
