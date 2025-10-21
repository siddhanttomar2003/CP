class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int op = numOperations;
        vector<int>ls(3e5 + 2);
        map<int, int>mp;
        for(int i = 0; i < n; i++){
            ls[nums[i] - k + 1e5]++;
            ls[nums[i] + k + 1e5 + 1]--;
            mp[nums[i] + 1e5]++;
        }
        int ans = 0;
        int wo = 0;
        if(mp.find(0) != mp.end())wo = mp[0];
        int rem = ls[0] - wo;
        ans = max(ans, wo + min(op , rem));
        for(int i = 1; i < 3e5 + 1; i++){
            ls[i] += ls[i - 1];
            if(mp.find(i) != mp.end()) ans = max(ans, mp[i] + min(op, ls[i] - mp[i]));
            else ans = max(ans, min(ls[i], op));
        }
        return ans;
    }
};