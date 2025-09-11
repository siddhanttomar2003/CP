class Solution {
public:
    int minSensors(int n, int m, int k) {
        int maxi = max(n, m);
        int mini = min(n, m);
        int rem = mini - (2 * k + 1);
        int ex =  (rem / (2 * k + 1) + (rem % (2 * k + 1) == 0 ? 0 : 1) + 1);
        int ans = (maxi / (2 * k + 1) + (maxi % (2 * k + 1) == 0 ? 0 : 1));
        if(rem > 0)return ans * (rem / (2 * k + 1) + (rem % (2 * k + 1) == 0 ? 0 : 1) + 1);
        return ans;
    }
};