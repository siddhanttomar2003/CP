class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        prev=nums[0];
        prev2=INT_MIN;
        for(int i=1;i<n;i++){
            int pick=INT_MIN;
            int not_pick=INT_MIN;
            if(i>1)pick=nums[i]+prev2;
           
            not_pick=prev;
            int curr=max(pick,not_pick);
            
            prev=curr;
           
        }

        return dp[n-1];
    }
};