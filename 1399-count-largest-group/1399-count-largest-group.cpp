class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int>mp;
        int maxi=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            int num=i;
            int sum=0;
            while(num){
                sum+=num%10;
                num/=10;
            }
            mp[sum]++;
            if(mp[sum]>maxi){
                maxi=mp[sum];
                ans=1;
            }
            else if(mp[sum]==maxi){
                ans++;
            }
        }
        return ans;
    }
};