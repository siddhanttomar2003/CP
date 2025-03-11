class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int ca=0,cb=0,cc=0;
        int i=0;int j=0;
        int ans=0;
        while(j<n){
            if(s[j]=='a')ca++;
            else if(s[j]=='b')cb++;
            else cc++;
            while(ca>0 && cb>0 && cc>0 ){
                ans+=(n-j);
                if(s[i]=='a')ca--;
                else if(s[i]=='b')cb--;
                else cc--;
                i++;
            }
            j++;
        }
        return ans;
    }
};