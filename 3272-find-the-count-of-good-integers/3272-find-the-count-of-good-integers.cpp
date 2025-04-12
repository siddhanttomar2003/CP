typedef long long ll;
class Solution {
public:
    ll cal_ans(ll num, vector<ll>&pre_fac, int n){
        map<ll,ll>mp;
        while(num){
            mp[num%10]++;
            num/=10;
        }
        ll with_zeroes=0;
        ll den=1;
        for(auto it:mp){
            if(it.second>1){
                den*=(pre_fac[it.second]);
            }
        }
        with_zeroes=pre_fac[n]/den;
        ll f_zero=0;
        if(mp.find(0)!=mp.end()){
            f_zero=(pre_fac[n-1]*mp[0])/den;
        }
        return with_zeroes-f_zero;
    }
    ll cal(int n, int k , vector<ll>&pre_fac, set<string>&vis,string curr,int i){
        if(i>n/2 || (n%2==0 && i>=n/2)){
           ll num=stoll(curr);
           ll ans=0;
           if(num%k==0){
             sort(curr.begin(),curr.end());
             if(vis.find(curr)==vis.end()){
               ans=cal_ans(num,pre_fac,n);
             }
             vis.insert(curr);
           }
           return ans;
        }
        ll ans=0;
        for(char a='0';a<='9';a++){
            if(a=='0' && i==0)continue;
            curr[i]=a;
            curr[n-i-1]=a;
            ans+=cal(n,k,pre_fac,vis,curr,i+1);
        }
        return ans;
    }
    long long countGoodIntegers(int n, int k) {
        vector<ll>pre_fac(n+1,0);
        ll curr=1;
        for(int i=1;i<=n;i++){
            curr*=i;
            pre_fac[i]=curr;
        }
        set<string>vis;
        string temp=string(n,' ');
        return cal(n,k,pre_fac,vis,temp,0);
    }
};