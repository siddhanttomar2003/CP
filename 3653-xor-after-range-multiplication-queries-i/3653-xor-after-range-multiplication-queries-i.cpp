class Solution {
public:
    typedef long long ll;
    const int m = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for(auto it : queries){
            int s = it[0];
            int e = it[1];
            int jump = it[2];
            ll value = it[3];
            while(s <= e){
                nums[s] = (value * (ll)nums[s]) % m;
                s += jump;
            }
        }
        int val = 0;
        for(auto it : nums){
            val ^= it;
        }
        return val;
    }
};