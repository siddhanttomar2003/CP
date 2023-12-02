class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int hash_array[26]={0};
        for(int i=0;i<chars.length();i++){
            hash_array[chars[i]-'a']++;
        }
        int s=0;
        for(int i=0;i<words.size();i++){
            bool flag=true;
            string t=words[i];
            int hash_check[26]={0};
            for(int j=0;j<t.length();j++){
             hash_check[t[j]-'a']++;
            }
            for(int k=0;k<26;k++){
                if(hash_check[k]>hash_array[k]){
                flag=false;
                break;
                }
            }
            if(flag)s+=t.length();
        }
        return s;

    }
};