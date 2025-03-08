class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        vector<int>pre(n+1,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(blocks[i]=='W'){
             count++;
            }
            pre[i+1]=count;
        }
        int mini=1e9;
        for(int i=0;i<=n;i++)cout<<pre[i]<<" ";
        for(int i=0;i<=n-k;i++){
           mini=min(mini,pre[i+k]-pre[i]);
        }
        return mini;
    }
};