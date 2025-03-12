class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0;
        int n=nums.size();
        int ind=upper_bound(nums.begin(),nums.end(),0)-nums.begin();
        pos=n-ind;
        int ind2=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int neg=-1;
        neg=ind2;
        return max(pos,neg);
    }
};