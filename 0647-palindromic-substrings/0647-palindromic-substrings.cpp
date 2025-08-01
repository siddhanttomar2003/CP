class Solution {
public:
    int isPal[1001][1001];
    bool build(string &s, int i, int j){
        if(j == i) return isPal[i][j] = 1;
        if(j < i)return 1;
        if(isPal[i][j] != -1)return isPal[i][j];
        if(s[i] == s[j]){
         isPal[i][j] = build(s, i + 1, j - 1);
        }
        else isPal[i][j] = 0;
        build(s, i + 1, j);
        build(s, i , j - 1);
        return isPal[i][j];
    }
    int countSubstrings(string s) {
        int n = s.size();
        memset(isPal, -1, sizeof(isPal));
        build(s, 0, n - 1);
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPal[i][j] == 1)count++;
            }
        }
        return count;
    }
};