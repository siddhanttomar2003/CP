class Solution {
public:
    bool checkValidString(string s) {
        int curr_s=0;
        int ex=0;
        for(auto it:s){
            if(it=='(')curr_s++;
            else if(it==')'){
                if(curr_s>0)curr_s--;
                else if(ex>0)ex--;
                else return false;
            }
            else {
                ex++;
            }
        }
        curr_s=0,ex=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')')curr_s++;
            else if(s[i]=='('){
                if(curr_s>0)curr_s--;
                else if(ex>0)ex--;
                else return false;
            }
            else ex++;
        }
        return true;
    }
};
