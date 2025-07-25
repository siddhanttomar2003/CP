class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        int sum = 0;
        for(auto it : nums){
            if(it >= 0){
                if(st.find(it) == st.end())sum += it;
                st.insert(it);
            }
        }
        if(st.size() == 0){
            return *max_element(nums.begin(), nums.end());
        }
        return sum;
    }
};