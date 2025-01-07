class Solution {
public:
const int m = 256;  // Base for character set size (ASCII)
bool rabin_karp(string text, string pattern) {
    int t_s = text.size();
    int p_s = pattern.size();
    if (p_s > t_s) return false;  // Early exit if pattern is larger than text

    const int mod = 1000;  // Prime modulus for hash function
    int hash_pat = 0, hash_txt = 0;
    int pp = 1;

    // Precompute the highest power of m used in the hash calculation
    for (int i = 0; i < p_s - 1; i++) {
        pp = (pp * m) % mod;
    }

    // Compute initial hash values for the pattern and the first window of the text
    for (int i = 0; i < p_s; i++) {
        hash_pat = (hash_pat * m + pattern[i]) % mod;
        hash_txt = (hash_txt * m + text[i]) % mod;
    }

    // Slide the pattern over the text one character at a time
    for (int i = 0; i <= t_s - p_s; i++) {
        // Check if current hash values match, then check characters one-by-one
        if (hash_pat == hash_txt) {
            bool check = true;
            for (int j = 0; j < p_s; j++) {
                if (text[i + j] != pattern[j]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                return true;
            }
        }

        // Calculate the hash for the next window of text
        if (i < t_s - p_s) {
            hash_txt = (m * (hash_txt - text[i] * pp)%mod + text[i + p_s]) % mod;
            if (hash_txt < 0) {
                hash_txt += mod;  // Ensure non-negative hash values
            }
        }
    }
    return false;
}

    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        sort(words.begin(),words.end(),[](string a, string b){
             return a.size()<b.size();
        }); 
        for(int i=0;i<words.size();i++){
             string p=words[i];
             for(int j=i+1;j<words.size();j++){
                string t=words[j];
                if(t.size()>p.size()){
                    if(rabin_karp(t,p)){
                        ans.push_back(p);
                        break;
                    }
                }
             }
        }
        return ans;

    }
};