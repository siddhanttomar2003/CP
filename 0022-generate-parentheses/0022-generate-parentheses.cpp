class Solution {
public:
     void gen(vector<string> &ans, string temp, int n , int o, int c){
        if(o==n && c==n){
            ans.push_back(temp);
            return;
        }
        if(o<n){
        gen(ans,temp+'(',n,o+1,c);
        }
        if(o>c)gen(ans,temp+')',n,o,c+1);
     }
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string>ans;
        gen(ans,temp,n,0,0);
        return ans;
    }
};