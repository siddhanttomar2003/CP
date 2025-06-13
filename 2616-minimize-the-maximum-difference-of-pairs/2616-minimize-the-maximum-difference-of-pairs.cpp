class Solution {
public:
    bool check(int m, vector<int>&nums, int p){
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-1;i++){
             if(nums[i+1]-nums[i]<=m){
                count++;
                i++;
             }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,h=nums[n-1]-nums[0];
        int ans=h;
        while(l<=h){
            int m = l+(h-l)/2;
            if(check(m,nums,p)){
                   ans=m;
                   h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};