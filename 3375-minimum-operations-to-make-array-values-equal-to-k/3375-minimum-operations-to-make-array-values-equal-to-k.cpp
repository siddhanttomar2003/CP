class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini=*min_element(nums.begin(),nums.end());
        if(k>mini)return -1;
        set<int>st(nums.begin(),nums.end());
        int size=st.size();
        if(mini==k)return size-1;
        return size;
    }
};