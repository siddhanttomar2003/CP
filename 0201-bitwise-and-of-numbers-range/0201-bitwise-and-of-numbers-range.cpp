class Solution {
public:
    typedef long long ll;
    int rangeBitwiseAnd(int left, int right) {
        ll num = 1;
        while(num <= right){
            if(num > left && num <= right)return 0;
            num *= 2ll;
        }
        int pos = -1;
        for(int i = 0; i < 32; i++){
            if((right & (1 << i))  && !(left & (1 << i)))pos = i;
        }
        // cout << pos << endl;
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            if((right & (1 << i)) && (left & (1 << i)) && pos < i){
                    ans |= (1 << i);
            }
        }
        return ans;
    }
};