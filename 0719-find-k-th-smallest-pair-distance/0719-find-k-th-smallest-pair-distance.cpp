class Solution {
public:
     int check(vector<int> &nums, int m){
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
               if(nums[j]-nums[i]<=m){
                count++;
               }
               else break;
            }
        }
        return count;

     }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int r=nums[n-1]-nums[0];
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(nums,mid)>=k){
               ans=mid;
               r=mid-1;
            }
            else l=mid+1;
        }
       return ans;
    }
};