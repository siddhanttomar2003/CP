class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int>ans;
        int n = a.size();
        stack<int>st;
        vector<int>vis(n, 0);
        for(int i = n - 1; i >= 0; i--){
            if(a[i] < 0)st.push(i);
            else {
                bool check = false;
                while(!st.empty() && a[i] >= abs(a[st.top()])){
                    if(a[i] == abs(a[st.top()]))check = true;
                    vis[st.top()] = 1;
                    st.pop();
                    if(check)break;
                }
                if(check)vis[i] = 1;
                else if(st.size() > 0)vis[i] = 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i])ans.push_back(a[i]);
        }
        return ans;
    }
};