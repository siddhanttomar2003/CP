class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long long a=nums[i];
                    long long b=nums[j];
                    long  long c=nums[k];
                    ans=max(ans,(a-b)*c);
                }
            }
        }
        return ans;
    }
};