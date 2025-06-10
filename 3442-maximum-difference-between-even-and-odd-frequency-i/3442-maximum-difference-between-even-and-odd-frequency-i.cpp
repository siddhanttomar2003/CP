class Solution {
public:
    int maxDifference(string s) {
        int maxi_odd = 0, mini_even = 1e6;
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 97]++;
        }
        for (int i = 0; i < 26; i++) {
            if(freq[i]!=0){
            if (freq[i] & 1)
                maxi_odd = max(maxi_odd, freq[i]);
            else
                mini_even = min(mini_even, freq[i]);
            }
        }
        return maxi_odd-mini_even;
    }
};