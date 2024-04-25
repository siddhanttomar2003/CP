class Solution {
public:
    int check (vector<int> &nums,int mid){
        int student=1;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<=mid){
                continue;
            }
            else {
                sum=nums[i];
                student++;
            }
        }
        return student;
    }
    int splitArray(vector<int>& nums, int k) {
        // using bs on answers
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        high=accumulate(nums.begin(),nums.end(),high);
        int ans=INT_MAX;
        while(low<=high){
          int mid=low+(high-low)/2;
          if(check(nums,mid)==k){
            ans=min(ans,mid);
            high=mid-1;
          }
          else if(check(nums,mid)<k) high=mid-1;
          else low=mid+1;
        }
        return ans;
    }
};