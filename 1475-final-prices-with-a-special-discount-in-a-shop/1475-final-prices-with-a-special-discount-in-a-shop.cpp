class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // last smaller;
        int n=prices.size();
        vector<int>ans(n);
        stack<int>st;ans[n-1]=prices[n-1];
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && prices[st.top()]>prices[i]){
                st.pop();
            }
            if(st.size()>0){
                ans[i]=prices[i]-prices[st.top()];
            }
            else ans[i]=prices[i];
            st.push(i);
        }
        return ans;
    }
};