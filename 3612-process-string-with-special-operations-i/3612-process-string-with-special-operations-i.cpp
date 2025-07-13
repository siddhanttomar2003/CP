class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(auto it : s){
            if(it == '*'){
                if(ans.size() > 0)
                ans.pop_back();
            }
            else if(it == '#')ans += ans;
            else if(it == '%'){
                reverse(ans.begin(), ans.end());
            }
            else {
                ans += it;
            }
        }
        return ans;
    }
};