class Solution {
public:
    string compressedString(string word) {
        string comp="";
        for(int i=0;i<word.size();i++){
            int curr=1;
            while(i+1< word.size() && word[i]==word[i+1] && curr<9){
                i++;curr++;
            }
            string t=to_string(curr);
            comp+=t;
            comp+=word[i];
        }
        return comp;
    }
};