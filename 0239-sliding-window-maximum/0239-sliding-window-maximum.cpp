class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0;
        map<int,int>mp;
        int n = nums.size();
        while(j < k){
            mp[nums[j]]++;
            j++;
        }
        vector<int>ans;
        while(j < n){
            auto it = mp.rbegin();
            ans.push_back(it -> first);
            mp[nums[i]]--;
            if(mp[nums[i]] == 0)mp.erase(nums[i]);
            i++;
            mp[nums[j]]++;
            j++;
        }
        auto it = mp.rbegin();
        ans.push_back(it -> first);
        return ans;
    }
};