class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>r(n,0),c(m,0);
        map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            int row=mp[arr[i]].first;
            int col=mp[arr[i]].second;
            r[row]++;
            c[col]++;
            if(r[row]==n || c[col]==m)return i;
        }
        return -1;
        
    }
};