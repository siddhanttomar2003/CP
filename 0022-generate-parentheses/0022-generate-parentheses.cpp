class Solution {
public:
    void cal(vector<string>&ans, int i, int n, int o, string &a){
      if(i==n){
        if(o==0)ans.push_back(a);
        return;
      }
      if(o>0){
        a+=')';
        cal(ans,i+1,n,o-1,a);
        a.pop_back();
      }
      a+='(';
      cal(ans,i+1,n,o+1,a);
      a.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        int open=0;
        vector<string>ans;
        string a="";
        cal(ans,0,2*n,open,a);
        return ans;
    }
};
