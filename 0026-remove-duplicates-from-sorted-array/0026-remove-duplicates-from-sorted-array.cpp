class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1])ans.push_back(nums[i]);
        }
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(j<ans.size()){
            nums[i]=ans[j];
            j++;
            }
        }
        return (int)ans.size();
    }
};