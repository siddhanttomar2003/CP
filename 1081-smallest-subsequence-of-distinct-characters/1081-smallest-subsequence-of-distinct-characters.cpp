class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>mp;// to keep the track of last index of every char
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        vector<int> visited(26,0);
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(!(visited[s[i]-'a'])){
                while(st.size()>0 && s[i]<st.top()/* means this is lexicographically smaller than the top of the stack element*/
                 && mp[st.top()]>i/* means there are further appearence of this char so we can take it in our stack further */){
                 visited[st.top()-'a']=0;
                 st.pop();
                }
                st.push(s[i]);
                visited[s[i]-'a']=1;
            } 
        }
        string ans="";
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};