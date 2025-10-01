class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int curr=numBottles;
        int ans=0;
        int em=0;
        while(curr>0){
            ans+=curr;
            em+=curr;
            curr=0;
            curr=em/numExchange;
            em-=(curr*numExchange);
        }
        return ans;

    }
};