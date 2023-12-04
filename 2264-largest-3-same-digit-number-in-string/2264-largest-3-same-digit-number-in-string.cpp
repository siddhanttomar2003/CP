class Solution {
public:
    string largestGoodInteger(string num) {
        string s="";
        vector<vector<int>>mpp;
        int j=0;
        
        for(int i=0;i<num.length()-1;i++){
            vector<int>mp;
            if(num[i]!=num[i+1]){
                mp.push_back(num[i]);
                mpp.push_back(mp);   
             }
                  else{
         while(num[i]==num[i+1]){
             mp.push_back(num[i]);
             i++;
         }
         mp.push_back(num[i]);
         mpp.push_back(mp);
         i--;
                  }
        }
        for(int i=0;i<mpp.size();i++){
          if(mpp[i].size()>=3){
              string t="";
              if(s.length()==0){
              for(int j=0;j<=2;j++){
                  t+=mpp[i][0];
              }
              s=t;
              continue;
              }
              if(mpp[i][0]>s[0]){
                  for(int j=0;j<mpp[i].size();j++){
                      s[j]=mpp[i][j];
                  }
              }
              
              
          }
        }
        return s;
    }
};