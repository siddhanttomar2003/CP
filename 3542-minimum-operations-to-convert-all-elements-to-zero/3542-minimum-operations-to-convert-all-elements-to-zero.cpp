class Solution {
public:
    int minOperations(vector<int>& nums) {
        // 0 2 3 2 0 3 3 2 0
        map<int, vector<int>>mp;
        set<int>st;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)st.insert(i);
            else mp[nums[i]].push_back(i);
        }
        int count = 0;
        for(auto it : mp){
            vector<int> &temp = it.second;
            for(int i = 0; i < temp.size(); i++){
                int curr = temp[i];
                auto it = st.lower_bound(curr);
                if(it == st.end()){
                    while(i < temp.size()){
                        st.insert(temp[i]);
                        i++;
                    }
                }
                else {
                    while(i < temp.size() && temp[i] < *it){
                        st.insert(temp[i]);
                        i++;
                    }
                    i--;
                }
                count++;
            }
        }
        return count;
    }
};