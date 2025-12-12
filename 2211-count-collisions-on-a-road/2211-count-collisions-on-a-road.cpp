class Solution {
public:
    int countCollisions(string d) {
        int n = d.size();
        int ans = 0;
        int count_r = 0, count_s = 0;
        for(int i = 0; i < n; i++){
            if(d[i] == 'R'){
                count_r++;
            }
            else if(d[i] == 'S'){
                ans += count_r;
                count_r = 0;
                count_s++;
            }
            else {
                if(count_r){
                    ans += 2;
                    ans += count_r - 1;
                    count_r = 0;
                }
                else if(count_s) {
                    ans++;
                }
            }
        }
        return ans;
    }
};