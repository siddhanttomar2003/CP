class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n + 1, 0);
        for(int i = 1; i <= n; i++){
            pre[i] += pre[i - 1] + nums[i - 1];
        }
        stack<int>st;
        vector<int>l_s(n, -1),n_s(n, n);
        st.push(0);
        for(int i = 1; i < n; i++){
            while(!st.empty() && nums[i] <= nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                l_s[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        st.push(n - 1);
        for(int i = n - 2; i >= 0; i--){
            while(!st.empty() && nums[i] <= nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                n_s[i] = st.top();
            }
            st.push(i);
        }
        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi,nums[i] * (pre[n_s[i]] - pre[l_s[i] + 1]));
        }
        return maxi;
    }
};