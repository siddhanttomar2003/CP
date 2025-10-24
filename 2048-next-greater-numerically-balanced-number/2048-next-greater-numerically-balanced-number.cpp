class Solution {
public:
    int nextBeautifulNumber(int n) {
        n++;
        while(true){
            map<int, int>mp;
            int curr = n;
            while(curr){
                mp[curr % 10]++;
                curr /= 10;
            }
            bool check = true;
            for(auto it : mp)if(it.first != it.second)check = false;
            if(check)return n;
            n++;
        }
        return 1e6;
    }
};