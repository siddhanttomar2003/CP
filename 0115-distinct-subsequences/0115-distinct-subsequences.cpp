class Solution {
public:
    const int mod =1e9+7;
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int>curr(m+1,0),prev(m+1,0);
        prev[0]=1;
        curr[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=(prev[j-1]+prev[j])%mod;
                }
                else curr[j]=prev[j];
            }
            prev=curr;
        }
        return prev[m];

    }
};