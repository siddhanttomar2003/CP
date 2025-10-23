class Solution {
public:
    bool hasSameDigits(string s) {
        while(true){
            string temp = "";
            for(int i = 0; i < s.size() - 1; i++){
                temp += (s[i] - 48 + s[i + 1] - 48) % 10;
            }
            if(temp.size() == 2)return temp[0] == temp[1];
            s = temp;
        }
        return false;
    }
};