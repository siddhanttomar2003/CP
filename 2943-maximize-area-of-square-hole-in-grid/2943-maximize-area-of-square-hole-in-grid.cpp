class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxi_r = 0, maxi_c = 0;
        n = hBars.size(), m = vBars.size();
        for(int i = 0; i < hBars.size(); i++){
            int count = 1;
            if(i + 1 < n && hBars[i] + 1 == hBars[i + 1]){
                count++;
                i++;
            }
            maxi_r = max(maxi_r, count);
        }
        for(int i = 0; i < vBars.size(); i++){
            int count = 1;
            if(i + 1 < m && vBars[i] + 1 == vBars[i + 1]){
                count++;
                i++;
            }
            maxi_c = max(maxi_c, count);
        }
        int mini = min(maxi_c, maxi_r);
        return (mini + 1) * (mini + 1);
    }
};