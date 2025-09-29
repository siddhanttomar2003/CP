class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        sort(values.begin(), values.end());
        int ans = 0;
        for(int i = 2; i < n; i++){
            ans += values[0] * values[1] * values[i];
        }
        return ans;
    }
};