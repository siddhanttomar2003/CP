class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                if(nums[i]==nums[nums[i]-1])continue;
                else {
                    swap(nums[i],nums[nums[i]-1]);
                    i--;
                }
            }
        }
        vector<int>Ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)Ans.push_back(nums[i]);
        }
        return Ans;
    }
};