class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        vector<int>vis(7,0);
        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                vis[tops[i]]++;
            }
            else {
                vis[tops[i]]++;
                vis[bottoms[i]]++;
            }
        }
        int ans=1e9;
        for(int i=1;i<=6;i++){
            if(vis[i]==n){
                int t=0,b=0;
                for(int j=0;j<n;j++){
                    if(tops[j]!=i){
                       b++;
                    }
                    else if(bottoms[j]!=i)t++;
                }
                ans=min(ans,min(t,b));
            }
        }
        if(ans==1e9)return -1;
        return ans;
    }
};