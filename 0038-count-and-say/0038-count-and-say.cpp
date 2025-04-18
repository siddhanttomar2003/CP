class Solution {
public:
    string rle(string a){
        string ans="";
        for(int i=0;i<a.size();i++){
            int count=1;
            while(i+1<a.size() && a[i+1]==a[i]){
                i++;
                count++;
            }
            ans+=(to_string(count)+a[i]);
        }
        return ans;
    }
    string recur(string s, int n){
        if(n==1)return "1";
         s=rle(recur(s,n-1));
        return s;
    }
    string countAndSay(int n) {
        return recur("",n);
    }
};