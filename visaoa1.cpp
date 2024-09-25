#include<bits/stdc++.h>
using namespace std;
// schedules
int f(vector<pair<int,int>> a, int l){
    int n=a.size();
    sort(a.begin(),a.end());

    int ans=0;
    for(int i=0;i<n;i++){
        int st=a[i].first;
        int et=a[i].second;

        if(ans+l<=st) return ans;
        ans=max(ans,et);
    }
    if(ans+l<=1440) return ans;
    else return -1;
}


int main()
{
 int n;cin>>n;
 vector<vector<pair<int,int>>>v;
 vector<pair<int,int>>m;
 for(int i=0;i<n;i++){
    vector<pair<int,int>>temp;
    int terms;cin>>terms;
    for(int j=0;j<terms;j++){
        int a,b;cin>>a>>b;
        temp.push_back({a,b});
        m.push_back({a,b});
    }
    v.push_back(temp);
 }
 int len;cin>>len;
//  for(int i=0;i<n;i++){
//     for(int j=0;j<v[i].size();j++){
//         cout<<v[i][j].first<<" "<<v[i][j].second<<endl;
//     }
//  }
sort(m.begin(),m.end());
int start=m[0].first;
int end=m[0].second;
if(start>len){
    cout<<0<<endl;
    return 0;
}
int last=INT_MIN;
last=max(last,end);
priority_queue<int,vector<int>,greater<int>>q;
q.push(end);
for(int i=1;i<m.size();i++){
    int las=q.top();
    while(q.size()>0 && q.top()<m[i].first){
       las=q.top();
       q.pop();
    }
    last=max(last,m[i].second);
    if(q.size()==0){
        if(m[i].first-las>=len){
            cout<<las<<endl;
            return 0;
        }
    }
    q.push(m[i].second);
}
if(1440-last>=len){
    cout<<last<<endl;
    return 0;
}
cout<<-1<<endl;

return 0;
}