class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1')count++;
            else {
            bool check = false;
            while(i < n && s[i] == '0'){
                i++;
                check = true;
            }
            i--;
            if(check)ans += count;
            }
        }
        return ans;
    }
};