class Solution {
public:
    bool isValid(int i, int j, int n , int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        if(n==1 && m==1)return 0;
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(pq.size()>0){
            auto it=pq.top();
            pq.pop();
            int old=it[0];
            int r=it[1];
            int c=it[2];
            for(int i=0;i<4;i++){
                int n_r=r+delRow[i];
                int n_c=c+delCol[i];
                if(isValid(n_r,n_c,n,m)){
                    int diff=abs(heights[n_r][n_c]-heights[r][c]);
                    int maxi=max(old,diff);
                    if(dis[n_r][n_c]>maxi){
                        dis[n_r][n_c]=maxi;
                        pq.push({maxi,n_r,n_c});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};