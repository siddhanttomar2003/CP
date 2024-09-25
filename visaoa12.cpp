#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;cin>>n>>m;
    vector<int>fish(n);
    vector<int>baits(m);
    for(int i=0;i<n;i++){
        cin>>fish[i];
    }
    for(int i=0;i<m;i++)cin>>baits[i];
    sort(fish.begin(),fish.end());
    sort(baits.begin(),baits.end());
    int i=n-1;
    int j=m-1;
    map<int,int>mp;
    int count=0;
    while(i>=0 && j>=0){
        if(fish[i]>baits[j] && mp.find(baits[j])==mp.end()){
            count++;
           mp[baits[j]]++;
        }
        else if(fish[i]>baits[j] && mp[baits[j]]<=2){
            count++;
            mp[baits[j]]++;
        }
        if(mp[baits[j]]==3){
            j--;
        }
        i--;
    }
    cout<<count<<endl;

return 0;
}