class Solution {
public:
    bool canChange(string s, string t) {
        int n=s.size();
        int i=0;int j=0;
        while(i<n && j<n){
            if(s[i]=='R' && t[j]=='L' || t[j]=='R' && s[i]=='L')return false;
            if(s[i]==t[j]){
                i++;j++;
            }
            else  if(t[j]=='L'){
                i++;
            }
            else if(s[i]=='R')j++;
            else if(s[i]=='L' && t[j]=='_' && i>j)j++;
            else if(t[j]=='R' && s[i]=='_' && i<j)i++;
            else {
                cout<<i<<" "<<j<<endl;
                return false;
            }
        }
        while(i<n){
            if(s[i]!='_')return false;
            i++;
        }
        while(j<n){
            if(t[j]!='_')return false;
            j++;
        }
        return true;
    }
};