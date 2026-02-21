class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int>st;
        st.insert(2), st.insert(5), st.insert(11), st.insert(17), st.insert(23);
        st.insert(3), st.insert(7), st.insert(13), st.insert(19), st.insert(29);
        int ans = 0;
        for(int i = left; i <= right; i++){
            int count = 0;
            for(int j = 0; j < 30; j++){
                if(i & (1 << j))count++;
            }
            if(st.find(count) != st.end())ans++;
        }
        return ans;
    }
};