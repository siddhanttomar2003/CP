class Solution {
public:
    int maxDistance(vector<int>& colors) {
        vector<int>f(101, -1), l(101, -1);
        int n = colors.size();
        for(int i = 0; i < n; i++){
            int c = colors[i];
            if(f[c] == -1){
                f[c] = i;
            }
            l[c] = i;
        }
        int maxi = 0;
        for(int i = 0; i <= 100; i++){
            for(int j = 0; j <= 100; j++){
                if(i != j && l[i] != -1 && l[j] != -1){
                    maxi = max({maxi, abs(l[i] - f[j]), (f[i] - l[j])});
                }
            }
        }
        return maxi;
    }
};