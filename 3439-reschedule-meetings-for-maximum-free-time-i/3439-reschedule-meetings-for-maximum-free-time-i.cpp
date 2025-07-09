class Solution {
public:
    int maxFreeTime(int t, int k, vector<int>& s, vector<int>& e) {
        int n = s.size();
        vector<int>gaps;
        gaps.push_back(s[0]);
        int end = e[0];
        for(int i = 1; i < n; i++){
            gaps.push_back(s[i] - end);
            end = e[i];
        }
        gaps.push_back(t - end);
        // for(int i = 0; i <= n; i++)cout << gaps[i] << " ";
        // cout << endl;
        for(int i = 1; i <= n; i++){
            gaps[i] += gaps[i - 1];
        }
        int maxi = gaps[0];
        for(int i = 0; i <= n - k; i++){
            int curr = 0;
            if(i == 0)curr = gaps[i + k];
            else curr = gaps[i + k] - gaps[i - 1];
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};