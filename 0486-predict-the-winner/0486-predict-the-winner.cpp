class Solution {
public: 
    int cal(vector<int>&nums, int i, int j, int curr){
        if(j<i)return 0;
        int w1=0;
        if(curr==0){
           w1=nums[i]+cal(nums,i+1,j,curr^1);
           w1=max(w1,nums[j]+cal(nums,i,j-1,curr^1));
        }
        else {
               w1=min(cal(nums,i+1,j,curr^1),cal(nums,i,j-1,curr^1));
        }
        return w1;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
       int first_max=cal(nums,0,n-1,0);
       int sum=0;
       for(int i=0;i<n;i++)sum+=nums[i];
       cout<<sum<<endl;
        return first_max>=sum-first_max;
    }
};