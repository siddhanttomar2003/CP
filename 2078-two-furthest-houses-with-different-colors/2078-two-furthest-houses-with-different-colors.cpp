class Solution {
public:
    int maxDistance(vector<int>& c) {
        int n = c.size();
        if(c[0] != c[n - 1])return n - 1;
        int maxi = 0;
        for(int i = n - 1; i > 0; i--){
            if(c[i] != c[0])maxi = i;
            break;
        }
        for(int i = 0; i < n - 1; i++){
            if(c[i] != c[n - 1]){
                maxi = max(maxi, n - 1 - i);
                break;
            }
        }
        return maxi;
    }
};