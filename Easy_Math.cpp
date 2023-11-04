#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int sum_multiply(int a)
{
    int b=a;
    int s=0;
    while(b>0){
        s+=b%10;
        b/=10;
    }
    return s;
    
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	 int n;
	 cin>>n;
	 int a[n];
	 for(int i=0;i<n;i++) 
        { cin>>a[i];}             
          	                 	          
	
	int ans=-1;
	int sum=-1;
	for(int i=0;i<n-1;i++){
	   sum=0;
	   for(int j=i+1;j<n;j++){
	       sum=sum_multiply(a[i]*a[j]);
	       ans=max(ans,sum);
	   }
	   
	}
	cout<<ans<<endl;

}
	return 0;
}
