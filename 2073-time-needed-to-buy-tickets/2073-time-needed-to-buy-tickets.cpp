class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int mini=tickets[k];
        int ans=0;
        for(int i=0;i<tickets.size();i++){
            if(i<=k)
            ans+=min(mini,tickets[i]);
            else{
                if(tickets[i]<mini)ans+=tickets[i];
                else ans+=mini-1;
            }
        }
        return ans;
    }
};