#include<bits/stdc++.h>
using namespace std;
int t,n,k,pb,ps,p[200005];
long long a[200005],maxxb,maxxs,b,s;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k>>pb>>ps;for(int i=1;i<=n;i++)cin>>p[i];for(int i=1;i<=n;i++)cin>>a[i];maxxb=0,maxxs=0,b=0,s=0;
		for(int i=1;i<=min(n,k);i++){
			b+=a[pb],s+=a[ps];
			maxxb=max(maxxb,b+(k-i)*a[pb]),maxxs=max(maxxs,s+(k-i)*a[ps]);
			pb=p[pb],ps=p[ps];
		}
		cout<<((maxxb==maxxs)?"Draw":((maxxb>maxxs)?"Bodya":"Sasha"))<<endl;
	}
}