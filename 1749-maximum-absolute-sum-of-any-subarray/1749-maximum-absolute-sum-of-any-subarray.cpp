class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int first=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
          if(sum+nums[i]>=0){
            sum+=nums[i];
             first=max(first,sum);
          }
          else {
            sum+=nums[i];
             first=max(first,sum);
            sum=0;
        }
        nums[i]=-nums[i];
        }
       
        int second=INT_MIN;
        int s=0;
        for(int i=0;i<n;i++){
            if(s+nums[i]>=0){
                s+=nums[i];
                second=max(second,s);
            }
            else {
               s+=nums[i];
               second=max(second,s);
                s=0;
            }
        }
      
        return max(first,second);
    }
};