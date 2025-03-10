class Solution {
public:
   int check(vector<int>&v, int k){
      string ansv="00000";
      int count=0;
      for(int i=0;i<26;i++){
       if(v[i]>0 && i==0)ansv[0]='1';
       else if(v[i]>0 && i==4)ansv[1]='1';
       else if(v[i]>0 && i==8)ansv[2]='1';
       else if(v[i]>0 && i==14)ansv[3]='1';
       else if(v[i]>0 && i==20)ansv[4]='1';
       else if(v[i]>0) count+=v[i]; 
      }
      if(count>k)return 1;
      else if(ansv=="11111" && count==k)return 2;
      return 0;
   }
    long long countOfSubstrings(string word, int k) {
        long long ans = 0;
        int n = word.size();
        vector<int> next_consonant(n);
        int last = n;
        for (int i = n - 1; i >= 0; i--) {
            next_consonant[i]=last;
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                word[i] == 'o' || word[i] == 'u') {
                   continue;
            }
            else last=i;
        }
        int i=0,j=0;
        vector<int>v(26,0);
        while(j<n){
         v[word[j]-97]++;
        while(i<j && check(v,k)==1){
                v[word[i]-97]--;
                i++;
         }
         
         while(check(v,k)==2 && i<j){
            ans+=(next_consonant[j]-j);
            v[word[i]-97]--;
            i++;
         }
         j++;
        }
        return ans;
    }
};