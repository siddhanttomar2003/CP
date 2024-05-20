class Solution {
public:
 
    int subsetXORSum(vector<int>& nums) {
        // take nottake
        int ans=0;
        long long n=nums.size();
       for(long long i=0;i<pow(2,n);i++){
        long long sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sum=sum^nums[j];
            }
        }
        ans+=sum;
       }
       return ans;
    }
};