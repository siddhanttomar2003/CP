class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        vector<int>copy=nums;
        for(int i=0;i<nums.size();i++){
             if(nums[i]%p==0)nums[i]=1;
             else nums[i]=0;
        }
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            int curr=0;
            vector<int>temp;
            for(int j=i;j<n;j++){
                curr+=nums[j];
                temp.push_back(copy[j]);
                if(curr<=k)st.insert(temp);
            }
        }
        return st.size();
    }
};