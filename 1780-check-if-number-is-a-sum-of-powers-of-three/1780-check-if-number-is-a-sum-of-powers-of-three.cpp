typedef long long ll;
class Solution {
public:
    bool checkPowersOfThree(int n) {
        set<int>st;
        while (n > 0) {
            ll curr = 0;
            while (pow(3, curr) <= n) {
                curr++;
            }
            curr--;
            if(st.find(curr)!=st.end())return false;
            st.insert(curr);
            n-=pow(3,curr);
        }
        return n==0;
    }
};