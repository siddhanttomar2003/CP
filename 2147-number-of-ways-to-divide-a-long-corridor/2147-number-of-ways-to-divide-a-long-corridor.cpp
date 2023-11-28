class Solution {
public:
    int numberOfWays(string corridor) {
        int mod=1e9+7;
        vector<int>s;
        int n=corridor.size();
        for(int i=0;i<n;i++ ){
            if(corridor[i]=='S')
            s.push_back(i);
        }

        if(s.size()==0 || s.size()&1){
            return 0;
        }

        long long int ans=1;
        for(int i=2;i<s.size();i=i+2){
            ans=(ans%mod*((s[i]-s[i-1]))%mod)%mod;
        }
        return (int)ans;
    }
};