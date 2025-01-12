class Solution {
public:
    bool check(string &s){
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
               st.push(i);
            }
            else {
                if(st.size()>0)st.pop();
                else {
                    return false;
                }
            }
        }
        return true;
    }
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n & 1)
            return false;
        if(check(s))return true;
        set<int> fixed_open, fixed_close;
        set<int> rem;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                if (s[i] == '(')
                    fixed_open.insert(i);
                else
                    fixed_close.insert(i);
            } else
                rem.insert(i);
        }
        for (auto it : fixed_close) {
            auto it2=fixed_open.lower_bound(it);
            if(it2==fixed_open.begin()){
               auto it4=rem.lower_bound(it);
               if(it4==rem.begin())return false;
               else {
                auto it5=prev(it4);
                rem.erase(it5);
               }
            }
            else {
                auto it3=prev(it2);
                fixed_open.erase(it3);
            }
        }
        for (auto it : fixed_open) {
            auto it2 = rem.upper_bound(it);
            if (it2 != rem.end()) {
                rem.erase(it2);
            } else
                return false;
        }
        return true;
    }
};