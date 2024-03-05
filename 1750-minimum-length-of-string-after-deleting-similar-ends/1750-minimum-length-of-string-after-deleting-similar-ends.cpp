class Solution {
public:
    int minimumLength(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<end&&s[start]==s[end]){
         char current=s[start];
         while(start<end&&s[start]==current){
             start++;
         }
         while(end>=start&& s[end]==current){
             end--;
         }    
        }
      return end-start+1;       
            }
};