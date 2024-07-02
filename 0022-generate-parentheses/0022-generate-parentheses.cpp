class Solution {
public:
    void recur(int i,vector<string>&ans,int n,string &temp ){
        if(i==2*n){
            ans.push_back(temp);
            return;
        }
        // open
        temp+='(';
        recur(i+1,ans,n,temp);
        temp.pop_back();
        temp+=')';
        recur(i+1,ans,n,temp);
        temp.pop_back();

    }
    bool check(string s){
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')st.push(s[i]);
            else {
                if(st.size()>0){
                    st.pop();
                }
                else return false;
            }
        }
        if(st.size()>0)return false;
        return true;
    }
    vector<string> generateParenthesis(int n) {
        int i=0;
        string temp="";
        vector<string>ans;
        recur(i,ans,n,temp);
        vector<string>f;
        for(int i=0;i<ans.size();i++){
          if(check(ans[i]))f.push_back(ans[i]);
        }
        return f;
    }
};