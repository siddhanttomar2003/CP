class Solution {
public:
    bool isprefix(string a, string s){
        for(int i=0;i<a.length();i++){
            if(a[i]!=s[i])return false;
        }
        return true;
    }
    bool issuffix(string a , string s){
        
        int k=a.length()-1;
        int j=s.length()-1;
        if(k>j)return false;
        
        int i=k;
        while(k>=0){
            if(a[k]!=s[j])return false;
            k--;j--;
        }
        return true;
       
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isprefix(words[i],words[j])&&issuffix(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};