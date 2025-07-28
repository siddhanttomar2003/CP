class Solution {
public:
    long long minEnd(int n, int x) {
        long long num=x;
        long long times=n-1;
        set<int>st;
        long long ans=0;
        vector<int>v1(64,0);
        vector<int>v2(64,0);
        for(long long i=0;i<64;i++){
             if(num&(1LL<<i))v1[64-i-1]=1;
             if(times&(1LL<<i))v2[64-i-1]=1;
        }
         int j=0;
        for(long long i=0;i<64;i++){
           if(!(v1[64-i-1])){
               if(v2[64-j-1]){
                 ans|=(1LL<<i);
               }
               j++;
           }
           else {
             ans|=(1LL<<i);
           }
        }
         return ans;

    }
};