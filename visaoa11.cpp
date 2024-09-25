#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long n,k;cin>>n>>k;
    vector<long long>temp(n);
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
    long long maxi= *max_element(temp.begin(),temp.end());
    map<long long , int>mp;
    int i=0;
    while(pow(k,i)<=maxi){
        mp[pow(k,i)]++;
        i++;
    }
    long long count=0;
    for(int i=0;i<n;i++){
        if(mp.find(temp[i])!=mp.end())count++;
    }
    cout<<count<<endl;

return 0;
}