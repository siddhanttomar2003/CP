class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxi=0;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
                int a=st.size();
                maxi=max(maxi,a);
            }
            else if(s[i]==')'){
                st.pop();
               
            }
        }
        return maxi;
    }
};