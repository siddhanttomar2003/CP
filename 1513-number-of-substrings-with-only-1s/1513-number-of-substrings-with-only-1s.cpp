class Solution {
public:
    int numSub(string s) {
        int ans=0;
        long long count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                 count=0;
                while(s[i]=='1'){
                  count++;i++;
                }
                i--;
                long long n=((count*(count+1)%1000000007)/2)%1000000007;
                ans=(ans+n)%1000000007;
            }
        }
        return ans;

    }
};