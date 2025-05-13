class Solution {
public:
    const int m = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < t; i++) {
            vector<int> n_f(26, 0);
            for (int j = 0; j < 26; j++) {
                
                    
                    if (j != 25) {
                        n_f[j + 1] = (n_f[j + 1] + freq[j]) % m;
                    } else {
                        n_f[0] = (n_f[0] + freq[j]) % m;
                        n_f[1] = (n_f[1] + freq[j]) % m;
                    }
                
            }
            freq = n_f;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + freq[i]) % m;
        }

        return ans;
    }
};
