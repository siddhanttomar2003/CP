class Solution {
public:
    bool isOperand(char c){
        return c=='&' | c=='!' | c=='|';
    }
    bool find_result(int ct, int cf, char op ){
        if(op=='|'){
            if(ct>0)return true;
        }
        if(op=='&'){
            if(cf==0)return true;
        }
        if(op=='!'){
             if(cf>0)return true; 

        }
        return false;

    }
    bool parseBoolExpr(string expression) {
        stack<char>op;
        stack<char>value;
        bool ans=false;
        for(int i=0;i<expression.size();i++){
            char c=expression[i];
            if(isOperand(c)){
                op.push(c);
            }
            else {
               if(c!=')'){
                value.push(c);
               }
               else {
                 bool curr_result=false;
                 int count_fa=0;int count_tr=0;
                 while(value.size()>0 && value.top()!='('){
                       if(value.top()=='f')count_fa++;
                       else if(value.top()=='t') count_tr++;
                       value.pop();
                 }
                 curr_result=find_result(count_tr,count_fa,op.top());
                 cout<<curr_result<<" ";
                 op.pop();value.pop();
                 if(curr_result)value.push('t');
                 else value.push('f');
                 ans=curr_result;
               }
            }
        }
         return ans;
    }
};