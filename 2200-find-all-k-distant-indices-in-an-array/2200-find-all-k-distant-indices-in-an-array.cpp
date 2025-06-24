class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        vector<int>pos;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == key)pos.push_back(i);
        }
        int size = pos.size();
        for(int i = 0 ; i < n ; i++){
            int ind1 = lower_bound(pos.begin(), pos.end(), i - k) - pos.begin();
            if(ind1 != size && abs(pos[ind1] - i) <= k)ans.push_back(i);
        }
        return ans;
    }
};