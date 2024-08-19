class Solution {
public:
    int cal(int n, int curr, int avail, vector<vector<int>>& dp) {
        if (curr > n) return 1e7;  // If current count exceeds target, return a large number
        if (curr == n) return 0;    // If current count matches the target, no more steps needed
        if (dp[curr][avail] != -1) return dp[curr][avail]; // Check if this state is already computed
         int copy=INT_MAX;int paste=INT_MAX;
         if(avail==0){
           copy =1+ cal(n,curr,curr,dp);
         }
         else {
             paste=1+cal(n,curr+avail,avail,dp);
             if(curr!=avail)
             copy=1+cal(n,curr,curr,dp);
         }
        
        return dp[curr][avail] = min(copy, paste); // Memoize and return the minimum steps
    }
    
    int minSteps(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); // Memoization table
        return cal(n, 1, 0, dp); // Start with 1 'A' and 1 available paste
    }
};
