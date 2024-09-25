#include<bits/stdc++.h>
using namespace std;


int main()
{

 int n,m;cin>>n>>m;
 vector<vector<char>>v(n);
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        char c;cin>>c;
        v[i].push_back(c);
    }
 }


  int maxi=INT_MAX;
    for(int i=0;i<m;i++){
        int las=n-1;
        for(int j=n-1;j>=0;j--){
             if(v[j][i]=='#')las=j;
             else if(v[j][i]=='F'){
                maxi=min(maxi,las-j-1);
             }
        }
    }
    if(maxi==INT_MAX) return 0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            if(v[i][j]=='F'){
                v[i][j]='-';
                v[i+maxi][j]='F';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cout<<v[i][j]<<" ";
        cout<<endl;
    }


return 0;
}