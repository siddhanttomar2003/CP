class Solution {
public:
    typedef long long ll;
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>temp;
        for(int i = 0; i < n; i++)if(nums[i] != 0)temp.push_back(nums[i]);
        if(temp.size() < 2)return 0;
        ll maxi = temp[0] * 1ll *  temp[1];
        n = temp.size();
        maxi = max(maxi, (temp[n - 1] * 1ll *  temp[n - 2]));
        maxi = max(maxi, abs(temp[0] * 1ll *  temp[n - 1]));
        maxi = abs(100000 * 1ll * maxi);
        return maxi;
    }
};