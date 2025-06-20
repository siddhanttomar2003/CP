class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr_maxi=nums[0];
        int n=nums.size();
        if(n==1)return true;
        if(curr_maxi==0)return false;
        for(int i=1;i<n-1;i++){
           curr_maxi--;
           if(curr_maxi==0 && nums[i]==0)return false;
           else curr_maxi=max(curr_maxi,nums[i]);
        }
        return true;
    }
};