const int m = 1e9+7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>v(n);
        for(int i=0;i<n;i++){
            if(arr[i]&1)v[i]=1;
            else v[i]=0;
        }
        int curr=0;
        int odd_sum=0,even_sum=0;
        int ans=0;
        vector<int>last_one(n);
        int last=n;
        for(int i=n-1;i>=0;i--){
            last_one[i]=last;
            if(v[i]==1)last=i;
        }

        for(int i=n-1;i>=0;i--){
           if(v[i]==1){
             curr++;
             if(curr&1){
                odd_sum=(odd_sum+last_one[i]-i)%m;
                ans=(ans+odd_sum)%m;
             }
             else {
                even_sum=(even_sum+last_one[i]-i)%m;
                ans=(ans+even_sum)%m;
             }
           }
           else {
              if(curr&1){
                ans=(ans+odd_sum)%m;
              }
              else ans=(ans+even_sum)%m;
           }
        }
        return ans;
    }
};