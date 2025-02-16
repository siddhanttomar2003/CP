class Solution {
public:
    void backtrack(vector<int>& res, vector<int>& seq, vector<bool>& used, int n, int i) {
        if (i == seq.size()) {
            res = max(res, seq); 
            return;
        }

        if (seq[i] != -1) {  
            backtrack(res, seq, used, n, i + 1);
            return;
        }

        for (int num = n; num >= 1; num--) {
            if (num == 1) {  
                if (!used[num]) {
                    seq[i] = num;
                    used[num] = true;
                    backtrack(res, seq, used, n, i + 1);
                    seq[i] = -1;
                    used[num] = false;
                }
            } else { 
                if (!used[num] && i + num < seq.size() && seq[i + num] == -1) {
                    seq[i] = seq[i + num] = num;
                    used[num] = true;
                    backtrack(res, seq, used, n, i + 1);
                    seq[i] = seq[i + num] = -1;
                    used[num] = false;
                }
            }
        }
    }

    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> res, seq(size, -1);
        vector<bool> used(n + 1, false);
        backtrack(res, seq, used, n, 0);
        return res;
    }
};
