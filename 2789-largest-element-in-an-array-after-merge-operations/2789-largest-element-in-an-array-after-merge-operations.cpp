class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long ans = 0;
        long long f_ans = 0;
        int n = nums.size();
        long long m_ans=*max_element(nums.begin(),nums.end());
        for (int i = n - 1; i > 0; i--) {
            ans = nums[i];
            while (i > 0 && ans >= nums[i - 1]) {
                ans += nums[i - 1];
                i--;
            }
            f_ans = max(f_ans, ans);
            ans = 0;
        }
        if(f_ans>=m_ans)return f_ans;
        else return m_ans;
    }
};
