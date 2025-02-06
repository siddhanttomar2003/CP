class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    if(i!=j)
                    mp[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto it:mp){
            int f=it.second;
            ans+=(f*(f-2));
        }
        return ans;
    }
};