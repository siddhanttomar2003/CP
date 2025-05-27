class Solution {
public:
    int differenceOfSums(int n, int m) {
        int tot=(n*(n+1))/2;
        int sum=0;
        for(int i=m;i<=n;i+=m){
            sum+=i;
        }
        int one=tot-sum;
        return one-sum;
    }
};