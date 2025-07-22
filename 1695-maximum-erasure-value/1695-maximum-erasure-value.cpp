class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        map<int,int>mp;
        int maxi = 0, sum = 0;
        while(j < n){
            mp[nums[j]]++;
            sum += nums[j];
            while(mp[nums[j]] > 1 && i < j){
                mp[nums[i]]--;
                sum -= nums[i];
                if(mp[nums[i]] == 0)mp.erase(nums[i]);
                i++;
            }
            maxi = max(maxi, sum);
            j++;
        }
        return maxi;
    }
};