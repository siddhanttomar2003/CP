class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)ans.push_back(nums[i]);
            else if(nums[i]>0){
                int nind=(i+nums[i])%n;
                ans.push_back(nums[nind]);
            }
            else {
                int ab=abs(nums[i])%n;
                int nind=i-ab;
                if(nind<0){
                    nind+=n;
                }
                ans.push_back(nums[nind]);
            }
        }
        return ans;
    }
};