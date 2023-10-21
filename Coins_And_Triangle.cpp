    
#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;cin>>n;
	    int i=1;int h=0;
	    while(n/i>0){ h++;n-=i;i++;}
	    cout<<h<<endl;
	}
	return 0;
}
