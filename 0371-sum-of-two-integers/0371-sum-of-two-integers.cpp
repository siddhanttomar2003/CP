class Solution {
public:
     int binaryToDecimal(string n){string num = n;int dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

     int subtract(int a, int b) {
    while (b != 0) {
        int borrow = (~a) & b;  // Calculate the borrow using bitwise NOT and bitwise AND
        a = a ^ b;              // XOR to get the sum without carry
        b = borrow << 1;        // Shift the borrow to the left to be used in the next iteration
    }
    return a;
}

    int getSum(int a, int b) {
        string ans="";
        int carry=0;
        
       if(a>=0&&b>=0||a<0&&b<0){
           bool flag=false;
           if(a<0&&b<0){
               a=abs(a);
               b=abs(b);
               flag=true;
           }
        while(a>0||b>0){
            if((carry&&(a&1||b&1))||((a&1)&&(b&1))){
                if(carry&&a&1&&b&1){
                    ans+='1';
                }
                else {
                    ans+='0';
                }
                carry=1;
                
            }
            else{
                if(carry||a&1||b&1)ans+='1';
                else ans+='0';
                carry=0;
            }
            a>>=1;
            b>>=1;
        }
        if(carry)ans+='1';
        reverse(ans.begin(),ans.end());
        int ab= binaryToDecimal(ans);
        if(flag)return -ab;
        else return ab;
       }
       else{
          if(abs(a)>abs(b)){
              if(a<0){
                  return -subtract(abs(a),abs(b));
              }
              else return subtract(abs(a),abs(b));
             
          }
          else{
              if(a<0){
                  return subtract(abs(b),abs(a));
              }
              else return -subtract(abs(b),abs(a));
          }

       }

       
    }
};