class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int len = 0;
        for(int i = 0; i < n; i++){
            vector<int>freq(26, 0);
            for(int j = i; j < n; j++){
                freq[s[j] - 97]++;
                int f = 0;
                bool flag = true;
                for(int k = 0; k < 26; k++){
                    if(freq[k] != 0){
                        if(f == 0)f = freq[k];
                        else {
                            if(f != freq[k])flag = false;
                        }
                    }
                }
                if(flag)len = max(len, j - i + 1);
            }
        }
        return len;
    }
};