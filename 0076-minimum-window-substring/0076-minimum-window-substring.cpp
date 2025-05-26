typedef long long ll;
class Solution {
public:
    bool valid (vector<ll>&t,vector<ll>&f){
        for(int i=0;i<256;i++){
            if(t[i]<f[i])return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        string ans="";
        ll start=-1,end=-1;
        ll len=1e10;
        if(s.size()<t.size())return ans;
        vector<ll>freq(256,0),temp(256,0);
        for(auto it:t)freq[it]++;
        ll j=0;
        ll i=0;
        ll n=s.size();
        while(j<n){
           temp[s[j]]++;
           while(valid(temp,freq) && i<=j){
              ll curr_len=j-i+1;
              if(curr_len<len){
                len=curr_len;
                start=i;
                end=j;
              }
              temp[s[i]]--;
              i++;
           }
           j++;
        }
        for(int i=start;i<=end;i++){
            ans+=s[i];
        }
        return ans;
    }
};
