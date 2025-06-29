class Solution {
public:
    int expand(string &s, int pos_s, int pos_e){
        int n=s.size();
        while(pos_s>=0 && pos_e<n && s[pos_s]==s[pos_e]){
            pos_s--;
            pos_e++;
        }
        return pos_e-pos_s-1;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int max_len=0;
        int start=-1,end=-1;
        for(int i=0;i<n;i++){
            int expand_for_odd=expand(s,i,i);
            int expand_for_even=expand(s,i,i+1);
            if(expand_for_odd>max_len){
              max_len=expand_for_odd;
              start=i-(max_len/2);
              end=i+(max_len/2);
            }
            if(expand_for_even>max_len){
              max_len=expand_for_even;
              start=i-(max_len/2)+1;
              end=i+(max_len/2);
            }
        }
        string ans="";
        for(int i=start;i<=end;i++){
              ans+=s[i];
        }
        return ans;
    }
};