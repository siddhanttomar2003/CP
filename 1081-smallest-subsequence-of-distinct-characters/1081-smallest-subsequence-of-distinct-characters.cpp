class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> count(26, 0);
        for (char c : text) {
            count[c - 'a'] += 1;
        }
        
        string result = "";
        vector<bool> used(26, false);
        for (char c : text) {
            if (used[c - 'a']) {
                count[c - 'a'] -= 1;
                continue;
            }
            while (!result.empty() and c < result.back() and count[result.back() - 'a'] > 0) {
                used[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(c);
            used[c - 'a'] = true;
            count[c - 'a'] -= 1;
        }
        return result;
    }
};