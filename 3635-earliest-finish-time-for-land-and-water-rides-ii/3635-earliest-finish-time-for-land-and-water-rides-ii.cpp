class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n = ls.size(), m = ws.size();
        int l = 1e9, w = 1e9;
        for(int i = 0; i < n; i++){
            l = min(l, ls[i] + ld[i]);
        }
        for(int i = 0; i < m; i++){
            w = min(w, ws[i] + wd[i]);
        }
        int ans1 = 1e9;
        for(int i = 0; i < m; i++){
            int curr = 0;
            if(ws[i] >= l)curr += ws[i] - l;
            ans1 = min(ans1, curr + l + wd[i]);
        }
        for(int i = 0; i < n; i++){
            int curr = 0;
            if(ls[i] >= w)curr += ls[i] - w;
            ans1 = min(ans1, curr + w + ld[i]);
        }
        cout << l << " " << w << endl;
        return ans1;
    }
};