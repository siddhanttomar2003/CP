class Solution {
public:
      int rev(int a){
          int reverse=0;
          while(a>0){
              reverse=reverse*10+a%10;
              a/=10;
          }
          return reverse;
      }
       
    long long countNicePairs(vector<int>& nums) {
        unordered_map<int,int>s;
        long long c=0;
        int n=nums.size();
        for(int i : nums){
            int x=i-rev(i);
            s[x]++;
        }
        long long mod=1e9+7;
        for(auto i : s){
            c=(c+(i.second%mod*(i.second-1)/2));
        }
       return c%mod;
    }
};