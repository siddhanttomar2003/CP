class Solution {
public:
     int max_mindiff(string t){
         int hash[26]={0};
         for(int i=0;i<t.size();i++){
             hash[t[i]-'a']++;
         }
         int maxx=INT_MIN;
         int minn=INT_MAX;
         for(int i=0;i<26;i++){
             if(hash[i]>maxx)maxx=hash[i];
             if(hash[i]<minn&&hash[i]!=0)minn=hash[i];
             
         }
         return maxx-minn;
     }
    int beautySum(string s) {
        int add=0;
        
        for(int i=0;i<s.size();i++){
            string t="";
            for(int j=i;j<s.size();j++){
                t+=s[j];
                add+=max_mindiff(t);
            }
          
        }
       return add;
    }
};