class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int n = nums.size();
        for(int i = 0; i < n; i++) pq.push({nums[i],i});
        vector<int>vis(n, 0);
        while(k--){
            int ind = pq.top().second;
            pq.pop();
            vis[ind] = 1;
        }
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(vis[i]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};