class Solution {
public:
    typedef long long ll;
    const int m = 1e9 + 7;
    int countNicePairs(vector<int>& nums) {
        map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            string temp = to_string(nums[i]);
            reverse(temp.begin(), temp.end());
            int num = stoi(temp);
            mp[nums[i] - num]++;
        }
        ll ans = 0;
        for(auto it : mp){
            ll freq = it.second;
            ans = (ans + (freq * (freq - 1)) / 2) % m;
        }
        return ans;
    }
};