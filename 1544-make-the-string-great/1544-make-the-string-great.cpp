class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
          if(s[i]>=97){
            if(st.size()>0 &&  st.top()+32==s[i])st.pop();
            else st.push(s[i]);
          }
          else {
              if(st.size()>0 &&  st.top()-32==s[i])st.pop();
            else st.push(s[i]);
          }
        }
        string ans="";
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};