#include <bits/stdc++.h>
using namespace std;
int find_ways(int i,int n,vector<vector<long long>> &dp){
    if(i<0 || n<0 || i>=6)return 0;
    if(n==0)return 1;
    if(dp[i][n]!=-1)return  dp[i][n];
    int take=0;int nottake1=0; int nottake2=0;
    take=find_ways(i,n-(i+1),dp);
    nottake1=find_ways(i+1,n,dp);
    nottake2=find_ways(i-1,n,dp);
    return dp[i][n]=take+nottake1+nottake2;
    
}
int main(){
    long n;
    cin>>n;
    vector<vector<long long>>dp(6,vector<long long>(n+1,-1));
    long long ways=find_ways(0,n,dp);
    cout<<ways%1000000007<<endl;
    return 0;
}