class Solution {
public:
    int minSwaps(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='[')st.push(i);
            else {
                if(st.size()>0){
                    st.pop();
                }
            }
        }
        return st.size()/2+st.size()%2;

    }
};