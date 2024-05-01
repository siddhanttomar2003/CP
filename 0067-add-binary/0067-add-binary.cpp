class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry=0;
        int i=a.length()-1;
        int j=b.length()-1;
        while(i>=0 && j>=0){
            int aa=a[i]-48;
            int bb=b[j]-48;
            int c=(aa+bb+carry)%2;
            carry=(aa+bb+carry)/2;
            ans+=to_string(c);
              i--;j--;
        }
        while(i>=0){
              int aa=a[i]-48;
              int c=(aa+carry)%2;
              carry=(aa+carry)/2;
              ans+=to_string(c);
              i--;
        }
        while(j>=0){
              int bb=b[j]-48;
              int c=(bb+carry)%2;
              carry=(bb+carry)/2;
              ans+=to_string(c);
              j--; 
        }
        if(carry==1)ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};