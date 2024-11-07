class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int maxi=0;
        vector<int>temp(32,0);
        int n=nums.size();
        for(int j=0;j<n;j++){
        for(int i=0;i<32;i++){
            if(nums[j]&(1<<i))temp[i]++;
        }
        }
        for(int i=0;i<32;i++){
            if(temp[i])maxi=max(maxi,temp[i]);
        }
        return maxi;

    }
};