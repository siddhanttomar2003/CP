class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>ans;
        int n=nums.size();
        vector<int>prefix(n);
         prefix[0]=0;
        int count=0;
        for(int i=0;i<n-1;i++){
          if(nums[i]%2==nums[i+1]%2)count++;
          prefix[i+1]=count;
        }
     for(int i=0;i<queries.size();i++){
        int s=queries[i][0];
        int e=queries[i][1];
         if(prefix[e]-prefix[s]==0)ans.push_back(true);
         else ans.push_back(false);
     }
     return ans;
    }
};