class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        vector<int> vis(n, 0);
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else {
                int ind = st.top();
                st.pop();
                if(st.size() == 0){
                    vis[i] = 1;
                    vis[ind] = 1;
                }
            }
        }
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(!vis[i])ans += s[i];
        }
        return ans;
    }
};