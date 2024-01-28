class Solution {
public:
    int countKeyChanges(string s) {
        int count=0;
        for(int i=0;i<s.length()-1;i++){
           if(abs(s[i+1]-s[i])==32||abs(s[i+1]-s[i])==0)continue;
          else count++;
        }
 return count;
    }
};