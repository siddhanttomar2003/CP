class Solution {
public:
    int numSteps(string s) {
      int count=0;
      int carry=0;
      for(int i=s.length()-1;i>=0;i--){
        if(i==0){
            if(s[i]=='1' && carry==0)continue;
            else {
                count++;
                continue;
            }
        }
        if(s[i]=='1' && carry==0){
            count+=2;
           carry=1;
        }
        else if(s[i]=='1' && carry==1){
            count+=1;
            carry=1;
        }
        else if(s[i]=='0' && carry==0){
            count+=1;
            carry=0;
        }
        else {
            count+=2;
            carry=1;
        }  
      }
      return count;
    }
};