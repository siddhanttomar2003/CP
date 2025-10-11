class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int>pre(n, 0);
        int maxi = -1e9;
        for(int i = n - 1; i >= n - k; i--){
            pre[i] = energy[i];
            maxi = max(maxi, pre[i]);
        }
        for(int i = n - k - 1; i >= 0; i--){
            pre[i] += (pre[i + k] + energy[i]);
            maxi = max(maxi, pre[i]);
        }
        return maxi;
    }
};