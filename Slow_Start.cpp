

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x,h;
	    cin>>x>>h;
	    int newx=x/2;
	   int turn=0;
	   int i=1;
	   while(h>0){
	       if(i<=5){
	           h-=newx;
	           turn++;
	           i++;
	       }
	       else{
	           h-=x;
	           turn++;
	       }
	   }
	   cout<<turn<<endl;
	    
	    
	}
	return 0;
}
