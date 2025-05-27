class Solution {
public:
    bool isOperator(string a){
        if(a.size()!=1)return false;
        return a[0]=='/' | a[0]=='+' | a[0]=='-' | a[0]=='*';
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto it:tokens){
            if(isOperator(it)){
                int num1=st.top();st.pop();
                int num2=st.top();st.pop();
                if(it=="+")st.push(num1+num2);
                else if(it=="-")st.push(num2-num1);
                else if(it=="/")st.push(num2/num1);
                else st.push(num1*num2);
            }
            else st.push(stoi(it));
        }
        return st.top();
    }
};