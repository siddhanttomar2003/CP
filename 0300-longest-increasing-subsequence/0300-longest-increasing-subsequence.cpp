class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        for(int i = 0; i < n; i++){
            auto it = st.lower_bound(nums[i]);
            if(it != st.end()){
                st.erase(it);
            }
            st.insert(nums[i]);
        }
        return (int)st.size();
    }
};
