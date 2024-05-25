#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool find_ans(string s, int index, unordered_set<string>& st, vector<int>& memo) {
        if (index == s.length()) {
            return true;
        }
        if (memo[index] != -1) {
            return memo[index];
        }
        string temp = "";
        for (int i = index; i < s.length(); i++) {
            temp += s[i];
            if (st.find(temp) != st.end()) {
                if (find_ans(s, i + 1, st, memo)) {
                    memo[index] = 1;
                    return true;
                }
            }
        }
        memo[index] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> memo(s.length(), -1);  // Initialize memo vector with -1 indicating uncomputed values
        return find_ans(s, 0, st, memo);
    }
};
