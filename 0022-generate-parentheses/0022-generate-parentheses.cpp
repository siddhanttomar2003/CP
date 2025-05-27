class Solution {
public:
    void cal(vector<string>&ans, int i, int n, int o, string a){
      if(i==n){
        if(o==0)ans.push_back(a);
        return;
      }
      if(o>0){
        cal(ans,i+1,n,o-1,a+')');
      }
      cal(ans,i+1,n,o+1,a+'(');
    }
    vector<string> generateParenthesis(int n) {
        int open=0;
        vector<string>ans;
        cal(ans,0,2*n,open,"");
        return ans;
    }
};
