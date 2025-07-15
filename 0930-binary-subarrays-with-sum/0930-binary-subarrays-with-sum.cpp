class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        map<int, int>mp;
        int sum = 0;
        mp[0] = 1;
        int count = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum >= goal){
                if(mp.find(sum - goal) != mp.end()){
                    count += mp[sum - goal];
                }
            }
            mp[sum] ++;
        }
        return count;
    }
};