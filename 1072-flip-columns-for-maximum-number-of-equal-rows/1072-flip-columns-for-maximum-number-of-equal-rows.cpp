class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
         
        unordered_map<string, int> mp;
        int res = 0;
        
        for(auto& i : matrix)
        {
            string s1;
            string s2;
            
            for(auto& j : i)
            {
                s1 += (j == 1 ? '1' : '0');
                s2 += (j == 1 ? '0' : '1');
            }
            
            res = max(res, max(++mp[s1], ++mp[s2]));
        }
        
        return res;
    }
};