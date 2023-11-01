class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>v(2);
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int j=0;
        for(auto i:mpp){
            if(i.second==1){
                v[j]=i.first;
                j++;
            }
        }
        return v;
    }
};