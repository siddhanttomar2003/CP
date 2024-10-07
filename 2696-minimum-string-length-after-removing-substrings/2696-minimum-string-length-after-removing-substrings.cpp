class Solution {
public:
    int minLength(string s) {
       int n=s.size();
          bool check=false;
          for(int i=0;i<n-1;i++){
            if(s[i]=='A' && s[i+1]=='B' || s[i]=='C' && s[i+1]=='D'){
                check=true;
            }
          }
          int rem=n;
         while(check){
          int count=0;
          string temp=s;
          string ans="";
          check=false;
          for(int i=0;i<temp.size();i++){
            if( i+1<temp.size() && temp[i]=='A' && temp[i+1]=='B' || temp[i]=='C' && temp[i+1]=='D'){
                count++;
                i++;
                check=true;
            }
            else {
               ans+=temp[i];
            }
          }
          rem-=(2*count);
          s=ans;
       }
       return rem;
    }
};