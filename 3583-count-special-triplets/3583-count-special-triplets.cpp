class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        map<ll, ll>freq, curr;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                freq[0]--;
                 ans = (ans + ((ll)freq[nums[i] * 2] - (ll)curr[nums[i] * 2]) * ((ll)curr[nums[i] * 2]) % mod) % mod;
                 freq[0]++;
            }
            else if(curr.find(nums[i] * 2) != curr.end()){
                ans = (ans + (freq[nums[i] * 2] - curr[nums[i] * 2]) * (curr[nums[i] * 2]) % mod) % mod;
            }
            curr[nums[i]]++;
        }
        return ans;
    }
};