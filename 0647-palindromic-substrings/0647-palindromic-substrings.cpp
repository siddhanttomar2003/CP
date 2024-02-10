class Solution {
public:
    bool check(string a){
        if(a.length()==1)return true;
        int i=0;int e=a.length()-1;
        while(i<e){
            if(a[i]!=a[e])return false;
            i++;e--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            string a="";
            for(int j=i;j<s.size();j++){
                a+=s[j];
                if(check(a))ans++;
            }
        }
        return ans;
    }
};