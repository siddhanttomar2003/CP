class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        vector<int>bmask(32,0);
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
                if(nums[j]&(1<<i)){
                    bmask[i]++;
                }
            }
        }
        // for(int i=0;i<32;i++){
        //     cout<<bmask[i]
        // }
        for(int i=n-1;i>=0;i--){
            long long curr=0;
            for(int j=0;j<32;j++){
                if(bmask[j]>=1){
                  curr+=pow(2,j);
                   bmask[j]--;
                }
            }
            if(k>0){
            ans=(ans+curr*curr)%1000000007;
            k--;
            }
            else break;
        }
        return ans;
        
    }
};