class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        // last_greater
        stack<int>st;
        int n=t.size();
        vector<int>ans(n);
        st.push(n-1);
        ans[n-1]=0;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && t[i]>=t[st.top()]){
                st.pop();
            }
            if(st.size()==0)ans[i]=0;
            else ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;
    }
};
