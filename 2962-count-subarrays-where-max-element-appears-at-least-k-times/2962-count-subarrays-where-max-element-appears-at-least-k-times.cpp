class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int count=0;
        int maxi=*max_element(nums.begin(),nums.end());
        int i=0;int j=0;
        while(j<nums.size()){
            if(count<k){
                if(nums[j]==maxi)count++;
                j++;
            }
            else{
                ans+=nums.size()-j+1;
                if(nums[i]==k){count--;}
                i++;
                
            }
        }
        return ans;
    }
};