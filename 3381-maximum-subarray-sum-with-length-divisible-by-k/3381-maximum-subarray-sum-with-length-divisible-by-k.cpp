class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> prefix_arr(k, 0);
        long long sum = 0;
        int ind = 0;
        // inital prefix array build up
        for(int i = 0; i< k-1; i++)
            {
                sum += nums[i];
                prefix_arr[ind+1] = sum;
                ind++;
            }
        
        long long max_sum = LLONG_MIN;
        // for each length calculate minimum sum to remove and maintain as a multiple of k
        while(ind < nums.size())
            {
                sum += nums[ind];
                int len = ind + 1;
                max_sum = max(max_sum, sum - prefix_arr[len % k]);
                prefix_arr[len % k] = min(sum, prefix_arr[len % k]);
                ind++;
            }
        return max_sum;
    }
};