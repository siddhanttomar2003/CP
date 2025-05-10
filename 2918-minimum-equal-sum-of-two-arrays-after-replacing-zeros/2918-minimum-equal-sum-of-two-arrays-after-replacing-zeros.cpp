typedef long long ll;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1=accumulate(nums1.begin(),nums1.end(),0*1ll);
        ll sum2=accumulate(nums2.begin(),nums2.end(),0*1ll);
        ll count1=0,count2=0;
        for(auto it:nums1)if(it==0)count1++;
        for(auto it:nums2)if(it==0)count2++;
        if(count1==0 || count2==0){
             if(count2==0 && sum1+count1>sum2){
                  return -1;
             }
             if(count1==0 && sum2+count2>sum1){
                  return -1;
             }
             return max(sum1+count1,sum2+count2);
        }
        return max(sum1+count1,sum2+count2);
    }
};