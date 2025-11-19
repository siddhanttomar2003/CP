class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        set<int>st;
        for(auto it : nums){
            if(it % o == 0)st.insert(it);
        }
        while(st.find(o) != st.end())o *= 2;
        return o;
    }
};