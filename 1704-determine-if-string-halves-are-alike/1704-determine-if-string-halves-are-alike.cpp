class Solution {
public:
    bool halvesAreAlike(string s) {
       int count1=0;
       int count2=0;
       int n=s.length();
       int j=n/2;
       for(int i=0;i<n/2;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='a'-32||s[i]=='e'-32||s[i]=='i'-32||s[i]=='o'-32||s[i]=='u'-32)count1++;
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='a'-32||s[j]=='e'-32||s[j]=='i'-32||s[j]=='o'-32||s[j]=='u'-32)count2++;
            j++;

       }
       return count1==count2;
    }
};