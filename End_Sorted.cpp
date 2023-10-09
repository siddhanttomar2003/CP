#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int pos1=-1;
	    int pos2=-1;
	    for(int i=0;i<n;i++){
	        if(v[i]==1)pos1=i;
	    }
	    int i=pos1;
	    while(i!=0){
	        swap(v[i],v[i-1]);
	        i--;
	    }
	    for(int l=0;l<n;l++){
	        if(v[l]==n)pos2=l;
	    }
	    int j=pos2;
	    int count2=0;
	    while(j<n-1){
	        swap(v[j],v[j+1]);
	        j++;
	        count2++;
	    }
	    cout<<pos1+count2<<endl;
	   
	}
	return 0;
}