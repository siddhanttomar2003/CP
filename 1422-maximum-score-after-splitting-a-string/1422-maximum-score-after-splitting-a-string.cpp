class Solution {
public:
    int maxScore(string s) {
        int sum=0;
       int count_one=0;
       int count_zero=0;
       int max_ans=0;
       for(int i=0;i<s.length();i++){
           if(s[i]=='1')count_one++;
       }
       for(int i=0;i<s.length()-1;i++){
         if(s[i]=='0')count_one++;
         else count_one--;
          max_ans=max(max_ans,count_one+count_zero);
       }
    return max_ans;
    }
};