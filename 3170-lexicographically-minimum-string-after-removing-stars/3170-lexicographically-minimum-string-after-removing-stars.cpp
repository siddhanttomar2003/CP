class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        map<char,vector<int>>mp;
        vector<int>vis(n,0);
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='*')mp[s[i]].push_back(i);
            else {
                vis[i]=1;
                char a = mp.begin()->first;
                int ind=mp.begin()->second.back();
                mp.begin()->second.pop_back();
                if(mp[a].size()==0)mp.erase(a);
                vis[ind]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i])ans+=s[i];
        }
        return ans;
    }
};