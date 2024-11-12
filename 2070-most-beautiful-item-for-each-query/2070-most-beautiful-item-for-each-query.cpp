class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        vector<int> pre_max(n);
        int curr = 0;
        vector<int> prices;
        for (int i = 0; i < n; i++) {
            prices.push_back(items[i][0]);
            curr = max(curr, items[i][1]);
            pre_max[i] = curr;
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int it = upper_bound(prices.begin(), prices.end(), queries[i]) -
                     prices.begin();
            it--;
            if (it >= 0) {
                ans.push_back(pre_max[it]);
                continue;
            }
            ans.push_back(0);
        }
        return ans;
    
}
};
