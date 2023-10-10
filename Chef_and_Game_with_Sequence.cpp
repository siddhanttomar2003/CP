#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int count1=0,count2=0;
	    for(int i=0;i<n;i++){
	        if(a[i]%2==0) count1++;
	        else count2++;
	    }
	    if(count2%2==0 || n==1) cout<<1<<endl;
	    else cout<<2<<endl;
	}
	return 0;
}
