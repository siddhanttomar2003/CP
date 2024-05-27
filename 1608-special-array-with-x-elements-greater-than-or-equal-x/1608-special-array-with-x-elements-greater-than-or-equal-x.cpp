class Solution {
public:
    int check(vector<int> &nums,int mid){
        int ans=0;
       for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]>=mid)ans++;
        else break;

       }
        return ans;
    }
    int specialArray(vector<int>& nums) {
        int i=0;
        int e=1000;
        sort(nums.begin(),nums.end());
        while(i<=e){
            int mid=i+(e-i)/2;
            int find=check(nums,mid);
            if(find==mid)return mid;
            else if(find>mid)i=mid+1;
            else e=mid-1;
        }
        return -1;
    }
};