class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //power set
        int n=nums.size();
        int total_sets=pow(2,n);
        vector<vector<int>>ans;
        for(int i=0;i<total_sets;i++){
            vector<int>v;
            for(int j=0;j<n;j++){
            if(i&(1<<j)){
                v.push_back(nums[j]);
            }     
            }
         ans.push_back(v);
        }
        return ans;
    }
};