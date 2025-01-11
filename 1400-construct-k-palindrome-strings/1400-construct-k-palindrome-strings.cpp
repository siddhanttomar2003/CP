class Solution {
public:
    bool canConstruct(string s, int k) {

        int n=s.size();
        if(n==k)return true;
        if(k>n)return false;
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
      int rem=n-k+1;
      if(rem&1){
        bool check_odd=false;
        for(auto it:mp){
            if(it.second&1 && !check_odd){
                int mini=min(rem,it.second);
                rem-=mini;
                check_odd=true;
            }
            else if(it.second&1 && check_odd){
                int mini=min(rem,it.second-1);
                rem-=mini;          
            }
            else {
                int mini=min(rem,it.second);
                rem-=mini;
            }
        }
      }
      else {
        for(auto it:mp){
            if(it.second&1 && rem>0){
                int mini=min(it.second-1,rem);
                 rem-=mini;
            }
            else if(it.second%2==0 && rem>0){
                int mini=min(it.second,rem);
                rem-=mini;
            }
        }
      }
      return rem==0;  
    }
};