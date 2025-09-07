class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n & 1){
            ans.push_back(0);
            n--;
        }
        int a = 1;
        for(int i = 0; i < n / 2; i++){
          ans.push_back(a);
          ans.push_back(-a);
          a++;
        }
        return ans;
    }
};