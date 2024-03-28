class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum=0;
        long long count=0;
        int i=0;int j=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum*(j-i+1)*1LL<k){
                j++;
            }
            else{
                while(sum*(j-i+1)>=k){
                    sum-=nums[i];
                    count+=j-i;
                    i++;
                }
                j++;
            }
        }
        long long n=j-i;
        count+=(n*(n+1))/2;
        return count;
    }
};