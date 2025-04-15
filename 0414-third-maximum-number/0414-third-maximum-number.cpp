typedef long long ll;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        ll maxi=-1e18;
        ll s_maxi=-1e18;
        ll t_maxi=-1e18;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                t_maxi=s_maxi;
                s_maxi=maxi;
                maxi=nums[i];
            }
            else if(nums[i]>s_maxi && nums[i]!=maxi){
                t_maxi=s_maxi;
                s_maxi=nums[i];
            }
            else if(nums[i]>t_maxi && nums[i]!=maxi && nums[i]!=s_maxi){
                t_maxi=nums[i];
            }
        }
        if(t_maxi==-1e18)return maxi;
        return t_maxi;

    }
};