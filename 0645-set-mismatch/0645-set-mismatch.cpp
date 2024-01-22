class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n=nums.size();
        long long sum=(n*(n+1))/2;
        long long sum_sq=(n*(n+1)*(2*n+1))/6;
         long long curr_sum=0;
         long long curr_sum_sq=0;
         for(int i=0;i<n;i++){
             curr_sum+=nums[i];
             curr_sum_sq+=nums[i]*1ll*nums[i];
         }
         int duplicate_no=((curr_sum-sum)+(curr_sum_sq-sum_sq)/(curr_sum-sum))/2;
         int missing_no=duplicate_no-curr_sum+sum;
         return {duplicate_no,missing_no};
    }
};