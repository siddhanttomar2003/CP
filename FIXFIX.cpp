#include <iostream>
using namespace std;

int main() {
    long long int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
        if(k==n-1)cout<<-1<<endl;
        else {
            long long int a[n];
            long long int t=n-k;
            t--;
            for(int i=0;i<n;i++)a[i]= i + 1;
            for(int i=0;i<n;i++){
                if(t>0){
                    swap(a[i],a[i+1]);
                    t--;
                }
                else break;
            }
            for(int i=0;i<n;i++)cout<<a[i]<<' ';
            cout<<endl;
        }
    }
	return 0;
}
