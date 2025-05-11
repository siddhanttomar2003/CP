class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        st.push(0);
        int n=num.size();
        if(k==1 && n==1 )return "0";
        vector<int>vis(n,0);
        for(int i=1;i<n;i++){
            while(!st.empty() && num[st.top()]>num[i] && k){
                k--;
                vis[st.top()]=1;
                st.pop();
            }
            st.push(i);
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(ans.size()==0 && num[i]=='0')continue;
                ans+=num[i];
            }
        }
        while(k-- && ans.size()>0){
            ans.pop_back();
        }
        if(ans.size()==0)ans+='0';
        return ans;
        
    }
};