class Solution {
public:
       bool isPalendrome(string &s){
        int i=0;int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int n=s.size(),m=t.size();
        set<string>st1,st2;
        int maxi=1;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                st1.insert(temp);
            }
        }
        for(int i=0;i<m;i++){
            string temp="";
            for(int j=i;j<m;j++){
                temp+=t[j];
                st2.insert(temp);
            }
        }
        for(auto it:st1){
            int size=it.size();
            string f=it,g=it;
            reverse(f.begin(),f.end());
            if(st2.find(f)!=st2.end()){
                maxi=max(maxi,size*2);
            }
            g.pop_back();
            reverse(g.begin(),g.end());
            if(st2.find(g)!=st2.end()){
                maxi=max(maxi,2*size-1);
            }
            if(isPalendrome(it))maxi=max(maxi,size);
        }
        for(auto it:st2){
            int size=it.size();
            string f=it;
            reverse(f.begin(),f.end());
            f.pop_back();
            if(st1.find(f)!=st1.end()){
                maxi=max(maxi,2*size-1);
            }
            if(isPalendrome(it))maxi=max(maxi,size);
        }
        return maxi;

    }
};