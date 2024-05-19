class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n=to_string(nums[0]).length();
        vector<vector<int>>mp(n,vector<int>(10,0));
        for(int i=0;i<nums.size();i++){
            string temp=to_string(nums[i]);
            for(int j=0;j<temp.length();j++){
                mp[j][temp[j]-'0']++;
            }
            
        }
        long long ans=0;
        for(auto it:mp){
           int sum=nums.size();
           for(int i=0;i<10;i++){
           ans+=(it[i]*(sum-it[i]));
           }

        }
        return ans/2;
        
    }
};