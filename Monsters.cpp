#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isprime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n<=1)return false;
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main() {
	int t;
	cin>>t;
	
	
	for(int i=0;i<t;i++){
	    int h;
	    cin>>h;
	   int count=0;
	   int ap=1;
	   
	 
	   while(h>0){
	         if(isprime(h)){
	           h=0;
	           count++;
	           break;
	       }
	       else{
	       
	       h=h-ap;
	       ap=2*ap;
	       count++;
	       }
	   }
	   if(h!=0){
	       cout<<-1<<endl;
	   }
	   else{
	       cout<<count<<endl;
	   }
	 
	}
	return 0;
}