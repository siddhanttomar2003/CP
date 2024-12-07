class Solution {
public:
    bool check(int m, vector<int>&nums, int op){
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=(nums[i]/m+ (nums[i]%m==0?0:1) -1);
        }
        if(curr<=op)return true;
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
          int i=1;
          int j=nums[n-1];
          int ans=j;
          while(i<=j){
            int m=(i+(j-i)/2);
            if(check(m,nums,maxOperations)){
                ans=m;
                j=m-1;
            }
            else i=m+1;
          }
          return ans;
    }
};