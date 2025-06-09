class Solution {
public:
    void cal(vector<vector<int>>&st,vector<int>&curr,vector<int>&nums,int i){
        if(i==nums.size()){
            st.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        cal(st,curr,nums,i+1);
        curr.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1])i++;
        cal(st,curr,nums,i+1);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>st;
        vector<int>curr;
        sort(nums.begin(),nums.end());
        cal(st,curr,nums,0);
        return st;
    }
};
