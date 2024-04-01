class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos=-1;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                pos=i;
                break;
            }
        }
        int len=0;
        if(pos==-1)return 0;
        for(int i=pos;i>=0;i--){
            if(s[i]==' '){
                break;
            }
            else len++;
        }
        return len;
    }
};