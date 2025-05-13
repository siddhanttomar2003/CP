class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int>v(26,0);
        for(int i=0;i<words.size();i++){
            for(auto it:words[i])v[it-97]++;
        }
        sort(words.begin(),words.end(),[](string &a,string &b){
             return a.size()<b.size();
        });
        int ans=0;
        for (int i = 0; i < words.size(); i++) {
            int req = words[i].size();
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