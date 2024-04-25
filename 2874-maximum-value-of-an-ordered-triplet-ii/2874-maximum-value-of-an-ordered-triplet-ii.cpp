class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //optimise to n^2
        int n=nums.size();
        vector<int>next_greater(n,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            next_greater[n-i-1]=maxi;
            maxi=max(maxi,nums[n-i-1]);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    long long a,b,c;
                    a=nums[i];b=nums[j];c=next_greater[j];
                    ans=max(ans,(a-b)*c);
                }
            }
        }
        return ans;
    }
};