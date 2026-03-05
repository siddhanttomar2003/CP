class Solution {
public:
    int minOperations(string s) {
        int mini1 = 0, mini2 = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                if(i & 1)mini1++;
                else mini2++;
            }
            else {
                if(i % 2 == 0)mini1++;
                else mini2++;
            }
        }
        return min(mini1, mini2);
    }
};