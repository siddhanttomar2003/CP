class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<int>pre(n+1,0);
        int sum=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+nums[i-1];
            sum+=nums[i-1];
        }
        int count=0;
        for(int i=1;i<n;i++){
            if((pre[i]-(sum-pre[i]))%2==0)count++;
        }
        return count;
    }
};