class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        vector<vector<int>> um;
        for(string &str : words)
        {
            vector<int> alphabet(26,0);
            for(char &ch : str)
            {
                alphabet[ch-'a']++;
            }
            um.push_back(alphabet);
        }
        int n = words.size();
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                vector<int> &si = um[i];
                vector<int> &sj = um[j];
                int x;
                for(x = 0; x < 26; ++x)
                {
                    if(si[x] > 0 && sj[x] > 0)
                        break;
                }
                if(x == 26)
                {
                    int mul = words[i].size() * words[j].size();
                    ans = max(ans, mul);
                }
            }
        }
        return ans;
    }
};