class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b')st.push(s[i]);
            else {
                if(st.size()==0)continue;
                else {
                    st.pop();
                    ans++;
                }
            }
        }
        return ans;
    }
};