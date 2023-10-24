#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int count0=0;
	int count1=0;
	for(int i=0;i<n;i++){
	    if(s[i]=='0')count0++;
	    else count1++;
	}
	int m=min(count1,count0);
	if(n%2!=0){
	    cout<<m*2+1<<endl;
	}
	else{
	    if(count0==count1)cout<<n<<endl;
	    else cout<<m*2+1<<endl;
	}
	}
	return 0;
}
