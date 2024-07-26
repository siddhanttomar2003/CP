class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=n-2;i>=1;i--){
            int f=nums[i+1];int s=nums[i];int t=nums[i-1];
            if(s+t>f)return s+f+t;
        }
        return 0;
    }
};