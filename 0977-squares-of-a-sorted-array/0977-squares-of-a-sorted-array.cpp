class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int a=abs(nums[i]);
            nums[i]=a*a;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};