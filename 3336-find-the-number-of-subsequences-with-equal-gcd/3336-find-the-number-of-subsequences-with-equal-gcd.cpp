class Solution {
public:
      int dp[201][201][201];
     int cal(int i, int gcd1, int gcd2, vector<int>&nums){
        if(i==nums.size()){
           return gcd1==gcd2;
        }
        if(dp[i][gcd1][gcd2]!=-1)return dp[i][gcd1][gcd2];
        int w1=cal(i+1,__gcd(gcd1,nums[i]),gcd2,nums);
        int w2=cal(i+1,gcd1,__gcd(gcd2,nums[i]),nums);
        int w3=cal(i+1,gcd1,gcd2,nums);
        return dp[i][gcd1][gcd2]=(((w1+w2)%1000000007)+w3)%1000000007;
     }
    int subsequencePairCount(vector<int>& nums) {
          memset(dp,-1,sizeof(dp));
        return cal(0,0,0,nums)-1;
    }
};