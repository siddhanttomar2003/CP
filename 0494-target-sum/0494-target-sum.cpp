class Solution {
public:
    void recur(vector<int> &nums,int target,int &count,int i){
       if(i==nums.size()){
        if(target==0)count++;
        return;
       }
       // plus
       recur(nums,target-nums[i],count,i+1);
       // minus
       recur(nums,target+nums[i],count,i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count=0;
        recur(nums,target,count,0);
        return count;
    }
};