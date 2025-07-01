class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        for(int i = 0; i < word.size(); i++){
            int count = 1;
            while(i + 1 < word.size() && word[i] == word[i + 1]){
                count++;
                i++;
            }
            ans += (count - 1);
        }
        return ans;
    }
};