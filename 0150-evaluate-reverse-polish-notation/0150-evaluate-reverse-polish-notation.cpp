class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>s;
        int ans=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/"){
                s.push(tokens[i]);
            }
            else {
                int a=stoi(s.top());
                s.pop();
                int b=stoi(s.top());
                s.pop();
                if(tokens[i]=="+")ans=a+b;
                else if(tokens[i]=="-")ans=b-a;
                else if(tokens[i]=="/")ans=b/a;
                else ans=a*b;
                s.push(to_string(ans));
            }
        }
        if(!s.empty()){
            ans=stoi(s.top());
            s.pop();
        }
        return ans;
    }
};