class Solution {
public:
    bool check(int m, vector<vector<int>>&Q, vector<int>&nums){
        int n=nums.size();
        vector<int>line_sweep(n+1,0);
        for(int i=0;i<=m;i++){
            int s=Q[i][0],e=Q[i][1];
            line_sweep[s]++;
            line_sweep[e+1]--;
        }
        if(nums[0]>line_sweep[0])return false;
        for(int i=1;i<n;i++){
            line_sweep[i]+=line_sweep[i-1];
            if(nums[i]>line_sweep[i])return false;
        }
        return true;
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int size=queries.size();
        int l=0,h=size-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(check(m,queries,nums)){
                return true;
            }
            else l=m+1;
        }
        return false;
    }
};