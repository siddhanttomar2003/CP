class Solution {
public:
    typedef long long ll;
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll>ans(n, 0);
        map<int, vector<ll>>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        for(auto it : mp){
            vector<ll>&temp = it.second;
            int size = temp.size();
            vector<ll>pre(size + 1, 0);
            for(int i = 0; i < size; i++){
                pre[i + 1] = pre[i] + temp[i];
            }
            ll suff = 0;
            for(int i = size - 1; i >= 0; i--){
                ll times_r = size - i - 1, times_l = i;
                ll right = suff;
                ans[temp[i]] = right - (times_r * temp[i]) + (times_l * temp[i]) - pre[i];
                suff += temp[i];
            }
        }
        return ans;
    }
};