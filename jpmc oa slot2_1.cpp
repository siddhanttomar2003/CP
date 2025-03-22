#include<bits/stdc++.h>
using namespace std;

int f(vector<int> &a){
    vector<int> x;
    vector<int> neg;
    for(auto it:a){
        if(it<0) neg.push_back(it);
        else x.push_back(it);
    }
    sort(neg.rbegin(),neg.rend());
    for(auto it:neg) x.push_back(it);

    long long count=0,sum=0;
    for(auto it:x){
        sum+=it;
        if(sum>0) count++;
    }
    return count;
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int x=f(a);
    cout<<x<<endl;
}