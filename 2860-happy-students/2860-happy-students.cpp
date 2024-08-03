class Solution {
public:
    int countWays(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i+1>nums[i] && i+1<n && nums[i+1]>i+1)count++;
            else if(i+1>nums[i] && i+1==n)count++;
            // else break;
        }
        if(nums[0]!=0)count++;
        return count;
    }
};