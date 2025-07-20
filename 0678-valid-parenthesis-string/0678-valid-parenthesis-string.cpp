class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st1, st2;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(')st1.push(i);
            else if(s[i] == '*')st2.push(i);
            else {
                if(st1.size() == 0){
                    if(st2.size() == 0)return false;
                    else st2.pop();
                }
                else {
                    st1.pop();
                }
            }
        }
        // all ) are balanced now
        while(st1.size() > 0 && st2.size() > 0){
            if(st2.top() > st1.top()){
                st1.pop();
                st2.pop();
            }
            else st2.pop();
        }
        return st1.size() == 0;
    }
};