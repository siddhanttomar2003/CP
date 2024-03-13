class Solution {
public:
    int pivotInteger(int n) {
        int prefix_sum=0;
        int i=1;
        while(i<=n){
            prefix_sum+=i;
            if(prefix_sum-i==((n*(n+1))/2)-prefix_sum)return i;
            i++;
        }
        return -1;
        }
};