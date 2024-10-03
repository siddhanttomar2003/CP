class Solution {
public:
    bool check(int m , vector<long long> &prefix, long long sum, int p){
        int i=0;
        while(i+m<prefix.size()){
            long long sub=prefix[i+m]-prefix[i];
            if((sum-sub)%p==0)return true;
            i++;
        }
        return false;
    }
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long sum=0;
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++){
           sum+=nums[i];
           prefix[i+1]=sum;
        }
        if(sum%p==0)return 0;
        int ans= -1;
        int l=1;
        int h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(mid,prefix,sum,p)){
                ans= mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;

    }
};