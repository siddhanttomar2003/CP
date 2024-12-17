class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> temp(26, 0);
        for (int i = 0; i < s.size(); i++) {
            temp[s[i] - 'a']++;
        }
        string ans = "";
        for (int i = 25; i >= 0; i--) {
            if (temp[i] > repeatLimit) {
                for (int j = 0; j < repeatLimit; j++) {
                    ans += (char)(97 + i);
                }
                bool check = false;
                char c = '#';
                for (int j = i - 1; j >= 0; j--) {
                    if (temp[j] > 0) {
                        check = true;
                        temp[j]--;
                        c = (char)(97 + j);
                        break;
                    }
                }
                if (check) {
                    ans += c;
                    temp[i] -= repeatLimit;
                    i++;
                } else
                    break;

            } else {
                for (int j = 0; j < temp[i]; j++) {
                    ans += (char)(97 + i);
                }
            }
        }
        return ans;
    }
};