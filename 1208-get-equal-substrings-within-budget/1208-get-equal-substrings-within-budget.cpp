class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len=0;
        int i=0;int j=0;
        int n=s.length();
        int curr_cost=maxCost;
        while(j<n){
           int req=abs(s[j]-t[j]);
           if(req<=curr_cost){
            curr_cost-=req;
            len=max(len,j-i+1);
            j++;
           }
           else {
            while(curr_cost<req){
                curr_cost+=abs(s[i]-t[i]);
                i++;
            }
           }
        }
        return len;
    }
};