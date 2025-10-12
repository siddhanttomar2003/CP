class Solution {
public:
    bool scoreBalance(string s) {
        int sum = 0;
        for(auto it : s){
            sum += (it - 96);
        }
        int curr = 0;
        int n = s.size();
        cout << sum << endl;
        for(int i = 0; i < n - 1; i++){
            curr += s[i] - 96;
            if(curr * 2 == sum)return true;
        }

        return false;
    }
};