class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        for(int i = 0; i < n; i++){
            while(nums[i] != i && nums[i] != nums[nums[i]]){
                swap(nums[i], nums[nums[i]]);
            }
            if(nums[i] == i)continue;
            if(nums[i] == nums[nums[i]])st.insert(nums[i]);
        }
        vector<int>ans;
        for(auto it : st)ans.push_back(it);
        return ans;
    }
};