#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    int count1,count2;
	    count1=0;count2=0;
	    int i=1;
	    while(a>=i){
	        a-=i;
	        i+=2;
	        count1++;
	    }
	    int j=2;
	    while(b>=j){
	        b-=j;
	        j+=2;
	        count2++;
	    }
	    if(count1>count2) cout<<"Limak"<<endl;
	    else cout<<"Bob"<<endl;
	}
	return 0;
}
