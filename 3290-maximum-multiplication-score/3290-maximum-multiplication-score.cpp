class Solution {
public:
    long long cal(vector<int>& a, vector<int>& b,int i,int j,vector<vector<long long>>&dp){
        if(i==4 && j==b.size()){
            return 0;
        }
        if(i==4)return 0;
        if(j==b.size()){
            return INT_MIN;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        long long t1=0;long long t2=0;
        t1=a[i]*b[j]+cal(a,b,i+1,j+1,dp);
        t2=cal(a,b,i,j+1,dp);
        return dp[i][j]=max(t1,t2);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        long long ans=0;
        int n=b.size();
        long long curr=0;
        vector<vector<long long>>dp(5,vector<long long >(n+1,-1));
        cal(a,b,0,0,dp);
        return dp[0][0];
    }
};