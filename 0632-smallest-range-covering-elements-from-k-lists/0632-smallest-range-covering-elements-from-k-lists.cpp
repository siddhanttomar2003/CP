class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        // initialize the pq with first value of each list
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            maxi = max(maxi, nums[i][0]);
        }
        vector<int> ans(2);
        ans[0] = -1e6;
        ans[1] = 1e6;
        while (true) {
            vector<int> curr = pq.top();pq.pop();
            int curr_ele = curr[0];
            int list_index = curr[1];
            int ele_index = curr[2];
            if (maxi - curr_ele < ans[1] - ans[0] ||
                (maxi - curr_ele == ans[1] - ans[0] && curr_ele < ans[0])){
                    ans[0]=curr_ele;
                    ans[1]=maxi;
                }

                if(ele_index+1<nums[list_index].size()){
                    pq.push({nums[list_index][ele_index+1],list_index,ele_index+1});
                    maxi=max(maxi,nums[list_index][ele_index+1]);
                }
                else {
                    break;
                }
        }
        return ans;
    }
};