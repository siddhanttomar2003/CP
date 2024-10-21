class Solution {
public:
    int cal(string &s, int i, unordered_set<string>&st, string curr){
        if(i==s.size())return 0;
        int t=0;int nt=0;
        curr+=s[i];
        if(st.find(curr)==st.end()){
            st.insert(curr);
            t=1+cal(s,i+1,st,"");
            st.erase(curr);
        }
         nt=cal(s,i+1,st,curr);
        return max(t,nt);

    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        return  cal(s,0,st,"");
    
    }
};