class Solution {
public:
    bool check(int m, vector<int>&c, long long k){
        long long a=0;
        if(m==0)return false;
        for(int i=0;i<c.size();i++){
            a += (c[i]/m)*1ll;
        }
        return a>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low=0;
        int high=*max_element(candies.begin(),candies.end());
        int ans=low;
        if(check(high,candies,k))return high;
        while(low<=high){
          int m=low+(high-low)/2;
          if(check(m,candies,k)){
              low=m+1;
              ans=m;
          }
          else high=m-1;
        }
        return ans;
    }
};