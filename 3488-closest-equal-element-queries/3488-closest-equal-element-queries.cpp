class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        map<int, vector<int>>mp;
        for(int i = 0; i < n; i++)mp[nums[i]].push_back(i);
        vector<int>ans;
        for(auto it : queries){
            int mini = 1e9;
            int ele = nums[it];
            vector<int>&temp = mp[ele];
            if(temp.size() == 1){
                ans.push_back(-1);
                continue;
            }
            int idx = lower_bound(temp.begin(), temp.end(), it) - temp.begin();
            int size = temp.size();
            if(idx + 1 < size){
                mini = min(mini, temp[idx + 1] - temp[idx]);
            }
            else {
                mini = min(mini, n - temp[idx] + temp[0]);
            }
            if(idx - 1 >= 0)mini = min(mini, temp[idx] - temp[idx - 1]);
            else mini = min(mini, n - temp[size - 1] + temp[idx]);
            
            ans.push_back(mini == 1e9 ? -1 : mini);
        }
        return ans;
    }
};