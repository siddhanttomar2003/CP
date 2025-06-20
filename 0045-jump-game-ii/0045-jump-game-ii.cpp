class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0;
        int count=0;
        int maxi=r;
        int n=nums.size();
        if(n==1)return 0;
        while(l<=r){
          maxi=max(maxi,l+nums[l]);
          if(maxi>=n-1)return count+1;
          if(l==r){
            l=r+1;
            r=maxi;
            maxi=0;
            count++;
          }
          else l++;
        }
        return -1;
    }
};