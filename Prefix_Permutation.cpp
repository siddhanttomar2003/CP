#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
int n,k;
cin>>n>>k;
int arr[k];
for(int i=0;i<k;i++){
    cin>>arr[i];
   
}
int ans[n];
int count=1;
for(int i=0;i<n;i++){
    ans[i]=count;
    count++;
}
int start=0;
for(int i=0;i<k;i++){
    int end=arr[i];
    int s=start;
    int e=end-1;
    while(s<=e){
        swap(ans[s],ans[e]);
        s++;e--;
    }
    start=end;
}
for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
}
cout<<endl;

}
return 0;
}
