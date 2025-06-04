class Solution {
public:
    string answerString(string s, int num) {
        int size=s.size();
       // covering the edge cases first 
       if(num == 1)return s;// no other option left just return the longest string
       if(num == 2){// string must be either the starting from 0 or ending at n-1
         string ans="";
         for(int i=0;i<size-1;i++){
               ans+=s[i];
          }
          for(int j=1;j<size;j++){
                string temp="";
             for(int k=j;k<size;k++){
                   temp+=s[k];
             }
             ans=max(ans,temp);
          }
         return ans;
        }
        string ans="";
        vector<int>possible;// store the idx of largest element;
       char c= *max_element(s.begin(),s.end());
       for(int i=0;i<size;i++){
           if(s[i]==c)possible.push_back(i);
      }
      for(int i=0;i<possible.size();i++){
              int curr=possible[i];
              int prev=curr;
              int rem=num-prev-1;
              int less=rem>0?rem:0;
               string temp="";
               for(int j=curr;j<size-less;j++){
                      temp+=s[j];
               }
              ans=max(ans,temp);
        }
return  ans;


    }
};