class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // using cyclic sort
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
             if(nums[i]==nums[nums[i]-1] && ans.size()==0)ans.push_back(nums[i]);
             else {
                swap(nums[i],nums[nums[i]-1]);
                i--;
             }
            }
        }
        
        for(int i=0;i<n;i++){
            if( i+1 !=nums[i]){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};