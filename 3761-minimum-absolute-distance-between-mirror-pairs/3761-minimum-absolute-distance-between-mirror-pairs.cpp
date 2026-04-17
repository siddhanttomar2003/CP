class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            string a = to_string(nums[i]);
            reverse(a.begin(), a.end());
            int b = stoi(a);
            if(mp.find(b) != mp.end()){
                auto idx = upper_bound(mp[b].begin(), mp[b].end(), i) - mp[b].begin();
                if(idx < mp[b].size()){
                    ans = min(ans, mp[b][idx] - i);
                }
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};