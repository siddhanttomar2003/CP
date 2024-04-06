class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char>st1;
        int count_o=0;
        int count_c=0;
        for(int i=0;i<s.length();i++){
          if(s[i]=='('){
            count_o++;
            st1.push(s[i]);
          }
          else if(s[i]!=')'){
            st1.push(s[i]);
          }
          else {
            count_c++;
            if(count_c<=count_o)st1.push(s[i]);
            else count_c--;

          }
        }
        string ans="";
        int count_open=0;
        int count_closed=0;
        while(st1.size()>0){
           if(st1.top()=='('){
            count_open++;
            if(count_open<=count_closed)ans+=st1.top();
             else count_open--;
           }
           else if(st1.top()==')'){
            count_closed++;
            ans+=st1.top();
           }
           else  ans+=st1.top();
           st1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};