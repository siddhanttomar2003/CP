#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,n,k;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    long int arr[n],sum=0;
	    for(long int i=0;i<n;i++){
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    if(k==1 and sum%2==0) cout<<"odd"<<endl;
	    else if(k==1 and sum%2!=0) cout<<"even"<<endl;
	    else cout<<"even"<<endl;
	}
	return 0;
}