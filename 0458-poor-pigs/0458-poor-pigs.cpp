class Solution {
public:
    int poorPigs(int B, int D, int T) {
        int op=log2(T/D+1);
        return ceil(log2(B)/op);
    }
};