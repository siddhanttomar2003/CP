typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll violation = -1;
        ll max_i = 1e9;
        ll min_i = 1e9;
        int maxi = -1;
        int mini = 1e9;
        int n=nums.size();
        ll ans=0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mini) {
                min_i = i;
                mini = nums[i];
            }
            if (nums[i] >= maxi) {
                max_i = i;
                maxi = nums[i];
            }
            if(nums[i]<minK || nums[i]>maxK){
                violation = i;
                mini= 1e9;
                maxi= -1;
            }
            if(mini==minK && maxi==maxK){
                ans+=(min(min_i,max_i)-violation);
            }
        }
        return ans;
    }
};