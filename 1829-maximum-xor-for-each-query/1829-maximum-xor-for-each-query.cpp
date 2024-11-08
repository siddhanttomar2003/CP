class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>ans;
        int n=nums.size();
        int x=0;
        for(int i=0;i<n;i++){
            x^=nums[i];
        }
        int j=n-1;
        for(int i=0;i<n;i++){
             int k=0;
             for(int j=0;j<maximumBit;j++){
                  if(!(x&(1<<j))){
                        k|=(1<<j);
                  }
             }
             ans.push_back(k);
             x^=nums[j];
             j--;
        }
        return ans;
    }
};