class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int len=INT_MAX;
        map<int,int>mp;
        mp[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
                sum+=nums[i];
                int rem=sum-target;
                if(mp.find(rem)!=mp.end()){
                    len=min(len,i-mp[rem]);
                }
                mp[sum]=i;
        }
        if(len==INT_MAX)return 0;
        return len;
    }
};