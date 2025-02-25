class Solution {
public:
    int findsum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=findsum(nums[i]);
            mp[sum].push_back(nums[i]);
        }
        int ans= -1;
        for(auto it:mp){
            vector<int>temp=it.second;
            sort(temp.begin(),temp.end());
            if(temp.size()>=2){
               int num1=temp.back();temp.pop_back();
               int num2=temp.back();
               ans=max(ans,num1+num2);
            }
        }
        return ans;

    }
};