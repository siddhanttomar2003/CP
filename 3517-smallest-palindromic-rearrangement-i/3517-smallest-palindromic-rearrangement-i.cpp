class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        map<char,int>mp;
        char c='0';
        for(int i=0;i<n;i++)mp[s[i]]++;
        int j=0;
        vector<char>ans(n);
        for(auto it:mp){
            if(it.second&1){
                c=it.first;
                  int freq=it.second;
                for(int i=0;i<freq/2;i++){
                     ans[j]=it.first;
                     ans[n-j-1]=it.first;
                     j++;
                }
            }
            else {
                int freq=it.second;
                for(int i=0;i<freq/2;i++){
                     ans[j]=it.first;
                     ans[n-j-1]=it.first;
                     j++;
                }
            }
        }
        if(c!='0')ans[j]=c;
        string f_ans ="";
        for(int i=0;i<n;i++){
            f_ans+=ans[i];
        }
        return f_ans;
    }
};