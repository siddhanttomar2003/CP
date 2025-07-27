class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>st;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > 0)st.insert(nums[i]);
        }
        int curr = 1;
        while(st.find(curr) != st.end())curr++;
        return curr;
    }
};