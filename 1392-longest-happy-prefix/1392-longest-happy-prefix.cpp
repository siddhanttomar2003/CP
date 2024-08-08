class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n);
        lps[0]=0;
        int len=0;
        int i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else {
                if(len!=0){
                    len=lps[len-1];
                }
                else {
                    lps[i]=0;
                    i++;
                }
            }
        }
        int maxi= -1;
         maxi=lps[n-1];
        if(maxi== -1)return "";
        string ans="";
        for(int i=0;i<maxi;i++){
               ans+=s[i];
        }
        return ans;
    }
};