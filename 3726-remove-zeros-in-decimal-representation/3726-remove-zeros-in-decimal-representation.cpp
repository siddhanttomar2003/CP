class Solution {
public:
    long long removeZeros(long long n) {
        string temp = "";
        string curr = to_string(n);
        for(int i = 0; i < curr.size(); i++){
            if(curr[i] != '0')temp += curr[i];
        }
        return stol(temp);
    }
};