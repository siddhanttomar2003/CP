typedef long long ll;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<ll>st(nums.begin(),nums.end());
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            ll num = nums[i];
            while(st.find(num) != st.end()){
                num --;
            }
            ll start = num + 1;
            int count = 0;
            while(st.find(start)!=st.end()){
                st.erase(start);
                start++;
                count++;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};