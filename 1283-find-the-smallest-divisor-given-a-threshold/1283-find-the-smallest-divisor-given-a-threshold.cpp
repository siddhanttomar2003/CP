class Solution {
public: 
    int check(vector<int> &nums,int &mid,int &threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid==0)sum+=nums[i]/mid;
            else sum+=nums[i]/mid+1;
            if(sum>threshold)return -1;
        }
        return 1;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i=1;
        int e=*max_element(nums.begin(),nums.end());
        int ans=e;
        while(i<=e){
            int mid=i+(e-i)/2;
            int f_ans=check(nums,mid,threshold);
            if(f_ans==1){
                ans=min(ans,mid);
                e=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};