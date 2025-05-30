class Solution {
public:
    typedef long long ll;
    bool check(ll m, vector<int>&p, int h){
        ll count=0;
        for(auto it:p){
            count+=((it*1ll)/m+(it%m==0?0:1));
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ll low=1;
        ll high=*max_element(piles.begin(),piles.end());
        ll ans=high;
        while(low<=high){
           ll m=low+(high-low)/2;
           if(check(m,piles,h)){
             ans=m;
             high=m-1;
           }
           else low=m+1;
        }
        return ans;
    }
};
