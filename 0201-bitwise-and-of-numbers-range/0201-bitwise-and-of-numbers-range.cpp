class Solution {
public:
    int binaryToDecimal(string n) {
        string num = n;
        int dec_value = 0;
        long long base = 1;
        int len = num.length();
        for (int i = len - 1; i >= 0; i--) {
            if (num[i] == '1')
                dec_value += base;
            base = base * 2;
        }
        return dec_value;
    }
    int rangeBitwiseAnd(int left, int right) {
        string ans = "";
        int i;
        for (i = 1; i <= 32; i++) {
           if((right&(1<<(32-i)))!=(left&(1<<(32-i)))){
                break;
           }
           else {
               if(right&(1<<(32-i)))ans+='1';
               else ans+='0';
           }
        }
        while (i <= 32) {
            ans += '0';
            i++;
        }
        int f_ans=binaryToDecimal(ans);
        return f_ans;
    }
};