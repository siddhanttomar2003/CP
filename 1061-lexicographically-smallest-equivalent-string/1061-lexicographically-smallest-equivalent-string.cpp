class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string ans="";
        int key=1;
        map<int,set<char>>mp;
        int n=s1.size();
        vector<int>vis(26,0);
        for(int i=0;i<s1.size();i++){
            char a=s1[i];
            char b=s2[i];
            // cout<<a<<" "<<b<<" "<<vis[a-97]<<" "<<vis[b-97]<<" "<<key<<endl;
            if(vis[a-97]==0 && vis[b-97]==0){
                vis[a-97]=key;vis[b-97]=key;
                mp[key].insert(a);
                mp[key].insert(b);
                key++;
            }
            else  {
                int k1=vis[a-97];
                int k2=vis[b-97];
                if(k1==0){
                    mp[k2].insert(a);
                    vis[a-97]=k2;
                }
                else if(k2==0){
                    mp[k1].insert(b);
                    vis[b-97]=k1;
                }
                else if(k1==k2)continue;
                else {
                    for(auto it:mp[k1]){
                        mp[k2].insert(it);
                        vis[it-97]=k2;
                    }
                    mp.erase(k1);
                }
            }
        }
        // for(auto it:mp){
        //     cout<<it.first<<" ->";
        //     for(auto it2:it.second)cout<<it2<<" ";
        //     cout<<endl;
        // }
        for(int i=0;i<baseStr.size();i++){
            char c=baseStr[i];
            if(!vis[c-97])ans+=c;
            else {
                int k=vis[c-97];
                ans+=*(mp[k].begin());
            }
        }
        return ans;
    }
};