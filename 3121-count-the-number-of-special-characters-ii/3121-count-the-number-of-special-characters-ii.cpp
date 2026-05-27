class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>freq1(26, -1), freq2(26, -1);
        int j = 0;
        for(auto it : word){
            if(it >= 97){
                freq1[it - 97] = j;
            }
            if(it >= 65 && it <= 90 && freq2[it - 65] == -1)freq2[it - 65] = j;
            j++;
        }
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(freq1[i] != -1 && freq2[i] != -1 && freq1[i] < freq2[i])count++;
        }
        return count;
    }
};