class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s=nums.size();
        vector<int>v;
        for(int i=0;i<s;i++){
            if(nums[i]!=0)v.push_back(nums[i]);
        }
        for(int i=0;i<s;i++){
            if(i<v.size()){
                nums[i]=v[i];
            }
            else {
                nums[i]=0;
            }
        }
    }
};