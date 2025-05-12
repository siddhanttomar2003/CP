class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=0;
        vector<int>odd,even;
        for(auto it:nums){
            if(it&1)odd.push_back(it);
            else even.push_back(it);
        }
        even.insert(even.end(),odd.begin(),odd.end());
        return even;
    }
};