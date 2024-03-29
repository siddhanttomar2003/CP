class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int count=0;
        int maxi=*max_element(nums.begin(),nums.end());
        int i=0;int j=0;
        while(j<nums.size()){
            if(nums[j]==maxi)count++;
            if(count<k){
                j++;
            }
            else{
                while(count>=k){
                    ans+=nums.size()-j;
                    if(nums[i]==maxi)count--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};