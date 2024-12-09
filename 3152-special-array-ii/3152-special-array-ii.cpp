class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<pair<bool,int>>pre(n,{true,-1});
        int last= -1;
        vector<bool>ans;
        for(int i=1;i<n;i++){
            if(nums[i]&1 && nums[i-1]&1){
                last=i;
                pre[i]={false,last};
            }
            else if(nums[i]%2==0 && nums[i-1]%2==0){
                last=i;
                pre[i]={false,last};
            }
            else {
                pre[i]={pre[i-1].first,last};
            }
        }
        for(int i=0;i<queries.size();i++){
            int end=queries[i][1];
            int start=queries[i][0];
            if(pre[end].first)ans.push_back(true);
            else {
                if(pre[end].second>start)ans.push_back(false);
                else ans.push_back(true);
            }
        }
        return ans;
    }
};