class Solution {
public:
    string decToBinary(int n) {
        string s = "";
        int i = 0;
        while (n > 0) {
            s = to_string(n % 2) + s;
            n = n / 2;
            i++;
        }
        return s;
    }

    long long minEnd(int n, int x) {
        if (n == 1)
            return x;
            string c=decToBinary(n-1);
           int  index=c.length()-1;
           string ans="";
           for(int i=0;i<64;i++){
            ans+='0';
           }
           for(int i=0;i<64;i++){
            if(  x>0 && x&1)ans[63-i]='1';
            else {
                if(index>=0){
                ans[63-i]=c[index];
                index--;
                }
                else ans[63-i]='0';
            }
            x>>=1;     
           }
           long long a=0;
           for(int i=63;i>=0;i--){
            if(ans[i]=='1'){
                a+=pow(2,63-i);
            }
           }
           return a;
    }
};