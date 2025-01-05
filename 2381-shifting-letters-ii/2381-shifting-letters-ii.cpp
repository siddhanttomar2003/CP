class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // using line sweep
        int n = s.size();
        vector<int> line_sweep(n, 0);
        for (int i = 0; i < shifts.size(); i++) {
            int s = shifts[i][0];
            int e = shifts[i][1];
            int add = (shifts[i][2] == 1 ? 1 : -1);
            line_sweep[s] += add;
            if (e + 1 < n)
                line_sweep[e + 1] -= add;
        }
        for (int i = 1; i < n; i++) {
            line_sweep[i] += line_sweep[i - 1];
        }
        for (int i = 0; i < n; i++) {
            line_sweep[i] %= 26;
        }
        for (int i = 0; i < n; i++) {
            int times = line_sweep[i];
            if (line_sweep[i] > 0) {
                for (int j = 0; j < times; j++) {
                    if (s[i] == 'z')
                        s[i] = 'a';
                    else
                        s[i] += 1;
                }
            } else {
                for(int j=0;j<abs(times);j++){
                    if(s[i]=='a')s[i]='z';
                    else s[i]-=1;
                }
            }
        }
        return s;
    }
};