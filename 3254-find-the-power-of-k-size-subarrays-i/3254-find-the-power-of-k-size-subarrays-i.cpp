class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<=n-k;i++){
            int maxi=-1;
            bool check=true;
            for(int j=i+1;j<i+k;j++){
                if(nums[j]-nums[j-1]==1){
                    continue;
                }
                else check=false;
            }
            if(check)maxi=nums[i+k-1];
            ans.push_back(maxi);
        }
        return ans;
    }
    
};