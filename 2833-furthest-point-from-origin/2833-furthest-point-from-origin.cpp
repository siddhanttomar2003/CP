class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int maxi = 0;
        int count1 = 0, count2 = 0;
        for(auto it : moves){
            if(it == 'L'){
                count1--;
                count2--;
            }
            else if(it == 'R'){
                count1++;
                count2++;
            }
            else {
                count1--;
                count2++;
            }
        }
        maxi = max({maxi, abs(count1), abs(count2)});
        return maxi;
    }
};