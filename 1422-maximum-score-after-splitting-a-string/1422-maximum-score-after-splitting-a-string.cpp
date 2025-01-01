class Solution {
public:
    int maxScore(string s) {
        int maxi=0;
        int zeroes=0;
        int ones=0;
        int n=s.size();
        for(int i=0;i<n;i++)if(s[i]=='0')zeroes++;
        for(int i=n-1;i>0;i--){
            if(s[i]=='1')ones++;
            else zeroes--;
            maxi=max(maxi,ones+zeroes);

        }
        return maxi;
    }
};