class Solution {
public:
    int minOperations(string s) {
     string t="";string k="";
        int changet=0;int changek=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0)
            {
                t+='0';
                k+='1'; 
                 if(s[i]!=t[i])changet++;
                 if(s[i]!=k[i])changek++; 
             }
            else {
                  t+='1';
                  k+='0';
                 if(s[i]!=t[i])changet++;
                  if(s[i]!=k[i])changek++;
                 }  
                      }
        return min(changet,changek);
    }
};