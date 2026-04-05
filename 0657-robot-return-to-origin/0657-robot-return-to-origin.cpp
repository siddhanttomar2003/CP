class Solution {
public:
    bool judgeCircle(string moves) {
        int y = 0, x = 0;
        for(auto it : moves){
            if(it == 'D')y--;
            else if(it == 'U')y++;
            else if(it == 'R')x++;
            else x--;
        }
        return x == 0 && y == 0;
    }
};