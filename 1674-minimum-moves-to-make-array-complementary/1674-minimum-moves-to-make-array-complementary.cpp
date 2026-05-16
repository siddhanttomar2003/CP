class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>diff(2 * limit + 2, 0);
        for(int i = 0; i < n / 2; i++){
            int a = nums[i], b = nums[n - i - 1];
            int mini = min(a, b);
            int maxi = max(a, b);
            diff[2] += 2, diff[2 * limit + 1] -= 2; 
            diff[mini + 1] -= 1;
            diff[maxi + limit + 1] += 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }
        int mini = 1e9;
        for(int i = 2; i <= 2 * limit; i++){
            diff[i] += diff[i - 1];
            mini = min(mini, diff[i]);
        }
        return mini;
    }
};