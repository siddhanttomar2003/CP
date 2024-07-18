class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int pro=1;
        int i=0;int j=0;
        int ans=0;
        int n=nums.size();
        while(j<n){
            pro*=nums[j];
            if(pro<k){
                j++;
            }
            else {
                while( i<=j && pro>=k){
                    pro/=nums[i];
                    ans+=(j-i);i++;
                }
                j++;
            }
        }
        int s=j-i;
        cout<<s<<endl;
        ans+=((s*(s+1))/2);
        return ans;
    }
};