class Solution {
public:
    void cal(set<string>&st,string &curr, string &tiles, int i,vector<int>&vis){
        if(i==tiles.size()){
            st.insert(curr);
            return;
        }
        for(int j=0;j<tiles.size();j++){
            if(!vis[j]){
                curr+=tiles[j];
                vis[j]=1;
                cal(st,curr,tiles,i+1,vis);
                vis[j]=0;
                curr.pop_back();
            }
        }
                cal(st,curr,tiles,i+1,vis);

    }
    int numTilePossibilities(string tiles) {
        set<string>st;
        int n=tiles.size();
        vector<int>vis(n,0);
        string curr="";
         cal(st,curr,tiles,0,vis);
         return st.size()-1;
    }
};