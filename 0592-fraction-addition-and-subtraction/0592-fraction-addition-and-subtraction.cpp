class Solution {
public:
    string fractionAddition(string expression) {
        int n=expression.size();
        vector<int>num;
        vector<int>den;
        for(int i=0;i<n;i++){
            if(expression[i]=='-'){
                i++;
                num.push_back(-(expression[i]-48));
                i++;
            }
            else {
                num.push_back(expression[i]-48);
                i++;
            }
            if(expression[i]=='/'){
                i++;
                den.push_back(expression[i]-48);
                i++;
                if(expression[i]=='+')continue;
                else i--;
            }
        }
        int lc=den[0];
        for(int i=1;i<den.size();i++){
            lc=(lc*den[i])/(__gcd(lc,den[i]));
        }
        cout<<lc<<endl;
        int nm=0;
        for(int i=0;i<num.size();i++){
          int req=lc/den[i];
         nm+=(num[i]*req);
        }
        int gg=__gcd(abs(nm),abs(lc));
        nm/=gg;
        lc/=gg;

        return to_string(nm)+"/"+to_string(lc);

    }
};