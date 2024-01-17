class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int n=nums.size();
        int prev=nums[0];
        bool flag=false;
        int main_ans=INT_MIN;
        for(int i=0;i<n;i++){
          if(i!=0&&prev==nums[i]){
              continue;
          }
          int s=i+1;
          int e=n-1;
          while(s<e){
              int sum=nums[i]+nums[e]+nums[s];
              int rem=abs(sum-target);
              if(rem<ans){
                  ans=rem;
                   main_ans=sum;
              }
              if(sum<target)s++;
              else if(sum>target)e--;
              else{
                  main_ans=sum;
                  flag=true;
                  break;
              }
             
              prev=nums[i];

          }
          if(flag)break;
        }
        return main_ans;
    }
};