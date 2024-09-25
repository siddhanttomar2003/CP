#include<bits/stdc++.h>
using namespace std;

long long calculateScore(int i, int j, vector<vector<int>>&grid){
    long long score=0;
    int m=grid[0].size();
    int curr=1;
    while(j!=m){
        score+=grid[i][j];
        j++;
        if(i==0)curr=0;
        if(curr==0)i++;
        else i--;
    }
    return score;
}
int main()
{
 int n;cin>>n;
 vector<vector<int>>grid(n,vector<int>(n));
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>grid[i][j];
    }
 }
 vector<pair<int,int>>ans;
 for(int i=0;i<n;i++){
   long long score= calculateScore(i,0,grid);
   ans.push_back({score,grid[i][0]});
 }
 sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++){
    cout<<ans[i].second<<" ";
  }
  cout<<endl;
return 0;
}