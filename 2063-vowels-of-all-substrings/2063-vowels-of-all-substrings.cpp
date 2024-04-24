class Solution {
public:
    long long countVowels(string word) {
        long long ans=0;
        long long n=word.size();
        for(int i=0;i<word.size();i++){
            if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'){
                 ans+=(n-i)*(i+1);
            }
        }
        return ans;
    }
};