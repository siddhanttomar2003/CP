class Solution {
public:
    string sortVowels(string s) {
        string ans = "";
        vector<char>v;
        int n = s.size();
        vector<int>f(n , 0);
        for(int i = 0; i < s.size(); i++){
            char c = tolower(s[i]);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                v.push_back(s[i]);
                f[i] = 1;
            }
        }
        sort(v.begin(), v.end());
        int k = 0;
        for(int i = 0; i < s.size(); i++){
            if(f[i]){
                ans += v[k];
                k++;
            }
            else ans += s[i];
        }
        return ans;
    }
};