class Solution {
public:
    bool check(int k , vector<int>&nums, vector<vector<int>>&q){
        int n=nums.size();
        vector<int>line_sweep(n+1,0);
        for(int i=0;i<k;i++){
          int s=q[i][0];
          int e=q[i][1];
          int wt=q[i][2];
          line_sweep[s]+=(wt);
          line_sweep[e+1]-=wt;
        }
        if(nums[0]-line_sweep[0]>0)return false;
        for(int i=1;i<n;i++){
            line_sweep[i]+=line_sweep[i-1];
            if(nums[i]-line_sweep[i]>0)return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       // already done the same question in codeforces 
       // in this type of format always think of bs
       bool flag=false;
       int n=queries.size();
       int low=0;
       int high=n;
       while(low<=high){
         int mid=(low+(high-low)/2);
         if(check(mid,nums,queries)){
            flag=true;
            high=mid-1;
         }
         else low=mid+1;
       }
       if(flag)return low;
       return -1;

    }

};