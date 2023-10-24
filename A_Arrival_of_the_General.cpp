#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
int h=INT32_MIN;
int posh=-1;
int l=INT32_MAX;
for(int i=0;i<n;i++){
    if(v[i]>h){
    h=v[i];
    posh=i;
    }
}
int counth=0;
for(int i=posh;i>0;i--){
swap(v[i],v[i-1]);
counth++;
}
int posl=-1;
for(int i=0;i<n;i++){
    if(v[i]<=l){
    l=v[i];
    posl=i;
    }

}
int countl=n-posl-1;
cout<<countl+counth<<endl;




	return 0;
}