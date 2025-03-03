class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
             ans[j]=nums[i];
             j++;
            }
        }
        int k=n-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>pivot){
                ans[k]=nums[i];
                k--;
            }
        }
        while(j<=k){
            ans[j]=pivot;
            j++;
        }
        return ans;

    }
};