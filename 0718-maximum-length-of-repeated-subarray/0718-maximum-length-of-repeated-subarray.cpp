class Solution {
public:
    int find_max(vector<int> &nums1,vector<int> & nums2,int index1,int index2,vector<vector<int>> &dp){
    // base case
     if(index1<0 || index2<0)return 0;
      if(dp[index1][index2]!=-1)return dp[index1][index2];
    int take=0;
    if(nums1[index1]==nums2[index2]){
        int i=index1;int j=index2;
        while(i>=0 && j>=0){
            if(nums1[i]==nums2[j]){
                take++;
                i--;j--;
            }
            else break;
        }
    }
    int nottake=max(find_max(nums1,nums2,index1-1,index2,dp),find_max(nums1,nums2,index1,index2-1,dp));
      return dp[index1][index2]=max(take,nottake);
    
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // using dp
        // we can use two indexes to find out till that what is the max substring we can get
        int index1=nums1.size();
        int index2=nums2.size();
        vector<vector<int>>dp(index1+1,vector<int>(index2+1,0));
         // now using the same concept as in largest common subseq
         // but here we dont have option for nottake 
         // This is bcz we need to have continous takes so nottake is not an option
            int ans=0;
          for(int i=1;i<=index1;i++){
            for(int j=1;j<=index2;j++){
                if(nums1[i-1]==nums2[j-1]){
                       dp[i][j]=1+dp[i-1][j-1];
                       ans=max(ans,dp[i][j]);
                }
            }
          }
          return ans;
      
       

    }
};