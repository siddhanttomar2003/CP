class Solution {
public:
    int minSwaps(string s) {
        int ans=0;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='[')st.push(s[i]);
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
      if(st.size()==0)return ans;
      else if(st.size()&1){
          ans=st.size()/2+1;
          return ans;
      }
      else {
          ans=st.size()/2;
          return ans;
      }
    }
};