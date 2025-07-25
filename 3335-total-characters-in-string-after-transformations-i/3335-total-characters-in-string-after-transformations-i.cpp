class Solution {
public:
    const int m = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<int>freq(26, 0);
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 97]++;
        }
        // for(int i = 0; i < 26; i++)cout << freq[i] << " ";
        // cout << endl;
        for(int i = 0; i < t; i++){
            vector<int>temp(26, 0);
            for(int j = 1; j < 25 ; j++){
                temp[j] = freq[j - 1];
            }
            temp[25] = freq[24];
            temp[0] = freq[25];
            temp[1] = (freq[25] + temp[1]) % m;
            // for(int j = 0; j < 26; j++)cout << temp[j] <<" ";
            // cout << endl;
            freq = temp;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
                ans = (ans + freq[i]) % m;
        }
        return ans;
    }

};