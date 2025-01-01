class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        map<pair<int,int>,vector<long long>>mp;
        for(long long i=0;i<n;i++){
            for(long long j=i+2;j<n;j++){
                mp[{nums[j]/__gcd(nums[i],nums[j]),nums[i]/__gcd(nums[i],nums[j])}].push_back(i);
            }
        }
        for(long long i=0;i<n;i++){
            for(long long j=i+2;j<n;j++){
                pair<int,int> cal={(nums[i]/__gcd(nums[i],nums[j])),(nums[j]/__gcd(nums[i],nums[j]))};
                vector<long long>temp=mp[cal];
                long long size=temp.size();
                long long ind=lower_bound(temp.begin(),temp.end(),j+2)-temp.begin();
                ans+=(size-ind);
            }
        }
        return ans;
    }
};