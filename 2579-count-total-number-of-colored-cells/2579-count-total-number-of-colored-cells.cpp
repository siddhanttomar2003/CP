class Solution {
public:
    long long coloredCells(int n) {
        long long a=n;
        long long b=n-1;
        return (a*a)+(b*b);
    }
};