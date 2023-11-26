class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        string s="";
         int pos=-1;
         for(int i=n-1;i>=0;i--){
             if((num[i]-'0')%2!=0){
                 pos=i;
                 break;
             }
         }
         if(pos==-1){
             return s;
         }
         for(int i=0;i<=pos;i++){
             s+=num[i];
         }
         return s;

    }
};