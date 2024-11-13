class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int x=lower-nums[i];
            long long start=lower_bound(nums.begin(),nums.end(),x)-nums.begin();
            start=max((int)start,i+1);
            int y=upper-nums[i];
            long long end=upper_bound(nums.begin(),nums.end(),y)-nums.begin();
            if(end==0){
                continue;
            }
            end--;
            if(end>=start){
                ans+=(end-start+1);
            }
        }
        return ans;
    }
};