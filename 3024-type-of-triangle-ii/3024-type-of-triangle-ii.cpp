class Solution {
public:
    string triangleType(vector<int>& nums) {
        bool ifpossible=false;
        if(nums[0]+nums[1]>nums[2]&&nums[1]+nums[2]>nums[0]&&nums[0]+nums[2]>nums[1]){
            ifpossible=true;
        }
        if(ifpossible){
        if(nums[0]==nums[1]&&nums[1]==nums[2])return "equilateral";
        else if(nums[0]==nums[1]||nums[1]==nums[2]||nums[0]==nums[2])return "isosceles";
        else return "scalene";
        }
        else return "none";
    }
};