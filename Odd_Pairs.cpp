#include <iostream>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
   
    long long odd=-1;
    long long even=-1;
    if(n%2==0){
        odd=n/2;
        even=n/2;
    }
    
    else {
        even=n/2;
        odd=even+1;
    }
    cout<<odd*even*2<<endl;
}
	return 0;
}
