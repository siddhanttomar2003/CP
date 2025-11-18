class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int ptr = 0;
        while(ptr < n){
            if(ptr + 1 < n){
                if(bits[ptr] && !bits[ptr + 1]) ptr += 2;
                else if(bits[ptr] && bits[ptr + 1])ptr += 2;
                else ptr += 1;
            }
            else {
                return true; 
            }
        }
        if(ptr == n)return false;
        return true;
    }
};