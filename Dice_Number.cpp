
#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	   int *arr=new int[6];
	   for(int i=0;i<6;i++){
	       cin>>arr[i];
	   }
	   int *a=new int[3];
	   int *b=new int[3];
	   int j=0;
	   int k=0;
	   for(int i=0;i<6;i++){
	       if(i<3){
	           a[j]=arr[i];
	           j++;
	       }
	       else{
	           b[k]=arr[i];
	           k++;
	       }
	   }
	   sort(a,a+3);
	   sort(b,b+3);
	int flag=0;
	for(int i=2;i>=0;i--){
	    if(a[i]>b[i]){
	        flag=1;
	        cout<<"Alice"<<endl;
	        break;
	    }
	    if(b[i]>a[i]){
	        flag=1;
	        cout<<"Bob"<<endl;
	        break;
	    }
	}
	   if(flag==0)cout<<"Tie"<<endl; 

	}
	return 0;
}
