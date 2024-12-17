class Solution {
public:
    bool check(vector<int>&vis){
        int last= -1;
        int n=vis.size();
        for(int i=n-1;i>=0;i--){
            if(vis[i]){
                last=i;break;
            }
        }
        for(int i=0;i<last;i++){
            if(!vis[i])return false;
        }
        return true;
    }
    int maxChunksToSorted(vector<int>& arr) {
        int tar=0;
        int n=arr.size();
        int count=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            vis[arr[i]]=1;
            if(check(vis))count++;
        }
        return count;
    }
};