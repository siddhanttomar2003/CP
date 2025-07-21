class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.size();
        for(int i = 0; i < s.size(); i++){
            int count = 1;
            ans += s[i];
            while(i + 1 < n && s[i] == s[i + 1]){
                count++;
                if(count <= 2)ans += s[i];
                i++;
            }
        }
        return ans;
    }
};