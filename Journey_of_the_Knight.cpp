#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int A,B,C,D;
	    cin>>A>>B>>C>>D;
	    int k=abs(A-C);
	    int l=abs(B-D);
	    if(k%2==l%2){
	        cout<<"YES"<<endl;
	    }
	  
	    else{
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
