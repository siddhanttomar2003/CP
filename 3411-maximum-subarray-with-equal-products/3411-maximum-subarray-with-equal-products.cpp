class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++){
            int pro=nums[i];
            int gcd=nums[i];
            int lcm=nums[i];
            for(int j=i+1;j<n;j++){
                gcd=__gcd(nums[j],gcd);
                lcm=(lcm*nums[j])/__gcd(lcm,nums[j]);
                if(pro>LLONG_MAX/nums[j])break;
                pro*=nums[j]*1ll;
                if(pro==lcm*gcd)ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};