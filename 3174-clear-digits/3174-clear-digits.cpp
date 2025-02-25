class Solution {
public:
    string clearDigits(string s) {
        stack<int>st;
        int n=s.size();
        int i=0;
        for( i=0;i<n;i++){
             if(s[i]>=48 && s[i]<=57){
                if(st.size()>0){
                    st.pop();
                }
                else break;
             }
             else {
                st.push(i);
             }
        }
        string ans="";
        while(st.size()>0){
            ans+=s[st.top()];
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        for(i;i<n;i++)ans+=s[i];
        return ans;

    }
};