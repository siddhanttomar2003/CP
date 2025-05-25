class Solution {
public:
   bool notValid(vector<int>&v, int k){
       int maxi=0;
       maxi=*max_element(v.begin(),v.end());
       int count=0;
       int sum=0;
       for(auto it:v){
        if(it==maxi && !count){
           count=1;
        }
        else sum+=it;
       }
       return sum>k;
   }
    int characterReplacement(string s, int k) {
       int len=0;
       int i=0,j=0;
       int n=s.size();
       vector<int>v(26,0);
       while(j<n){
           v[s[j]-65]++;
           if(notValid(v,k) && i<j){
            len=max(len,j-i);
            v[s[i]-65]--;
            i++;
           }
           j++;
       } 
       len=max(len,j-i);
       return len;
    }
};
