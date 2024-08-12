class Solution {
public:
    bool palendrome(string& temp) {
        int i = 0;
        int j = temp.length() - 1;
        while (i < j) {
            if (temp[i] != temp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n = words.size();
        vector<int> v(26, 0);
        int ans = 0;
        vector<int> npal;
        for (int i = 0; i < n; i++) {
            string temp = words[i];
            if (palendrome(temp)) {
                ans++;
                if (temp.length() & 1) {
                    v[temp[temp.length() / 2] - 'a']++;
                }
            } else {
                for (int j = 0; j < temp.length(); j++) {
                    v[temp[j] - 'a']++;
                }
                npal.push_back(temp.length());
            }
        }
        sort(npal.begin(), npal.end());
        for (int i = 0; i < npal.size(); i++) {
            int req = npal[i];
            bool odd = req & 1;
            if (odd)
                req--;
            vector<int> tempo = v;
            for (int j = 0; j < 26; j++) {
                if (v[j] % 2 == 0 && v[j] > 0) {
                    int mini = min(v[j], req);
                    v[j] -= mini;
                    req -= mini;
                } else if (v[j] & 1) {
                    int mini = min(v[j] - 1, req);
                    v[j] -= mini;
                    req -= mini;
                }
                if (req == 0 && odd == 0) {
                    ans++;
                    break;
                }
            }
            if (odd && req == 0) {
                for (int j = 0; j < 26; j++) {
                    if (v[j] & 1) {
                        odd = 0;
                        v[j]--;
                        ans++;
                        break;
                    }
                }
                if (odd) {
                    for (int j = 0; j < 26; j++) {
                        if (v[j] > 0) {
                            v[j]--;

                            ans++;
                            break;
                        }
                    }
                }
            }
            if (req != 0 || odd) {
                v = tempo;
            }
        }
        return ans;
    }
};