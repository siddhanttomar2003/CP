#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;

int main(){
    int n,k;
    cin>>n>>k;
    vector<pi>v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),[](pi a, pi b){
       if(a.second!=b.second)return a.second<b.second;
       return a.first<b.first;
    });
    int count=1;
    int busy=1;
    priority_queue<int,vi,greater<int>>pq;
    pq.push(v[0].second);
    for(int i=1;i<n;i++){

     int s=v[i].first,e=v[i].second;
     while(!pq.empty() && pq.top()<=s){
        busy--;
        pq.pop();
     }
     if(busy<k){
        count++;
        busy++;
        pq.push(e);
     }

    }
    cout<<count<<endl;
    return 0;
}