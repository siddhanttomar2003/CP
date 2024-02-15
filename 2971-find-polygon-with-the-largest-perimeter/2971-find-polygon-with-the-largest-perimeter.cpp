class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long prefix_sum=0;
        prefix_sum+=nums[0]+nums[1];
        long long perimeter=-1;
        for(int i=2;i<nums.size();i++){
            if(nums[i]<prefix_sum){
                perimeter=prefix_sum+nums[i];
            }
            prefix_sum+=nums[i];
        }
        return perimeter;

    }
};