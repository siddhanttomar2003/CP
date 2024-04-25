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
        int mmaxi=0;
        vector<int>prev_greater(n,0);
        for(int i=0;i<n;i++){
            prev_greater[i]=mmaxi;
            mmaxi=max(mmaxi,nums[i]);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
           if(prev_greater[i]>nums[i]){
            long long a=prev_greater[i];
            long long b=nums[i];
            long long  c=next_greater[i];
            ans=max(ans,(a-b)*c);
           }
        }
       
        
        return ans;
    }
};