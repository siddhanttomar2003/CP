class Solution {
public:
    bool check(vector<int> & curr, vector<int> &temp){
        for(int i=0;i<26;i++){
            if(curr[i]!=temp[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> temp(26, 0);
        int n = s1.size();
        int m = s2.size();
        if (m < n)
            return false;
        for (int i = 0; i < n; i++) {
            temp[s1[i] - 97]++;
        }
        vector<int> curr(26, 0);
        int i = 0;
        int j = 0;
        for (j; j < n; j++) {
            curr[s2[j] - 97]++;
        }

        while (j < m) {
            if (check(curr, temp)) {
                return true;
            }
            curr[s2[j] - 97]++;
            curr[s2[i] - 97]--;
            i++;
            j++;
        }
        if (check(curr, temp))
            return true;
        return false;
    }
};