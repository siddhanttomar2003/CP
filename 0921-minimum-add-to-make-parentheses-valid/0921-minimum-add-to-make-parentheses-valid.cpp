class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else {
                if(st.size()>0){
                    st.pop();
                }
                else ans++;
            }
        }
        return ans+st.size();
    }
};