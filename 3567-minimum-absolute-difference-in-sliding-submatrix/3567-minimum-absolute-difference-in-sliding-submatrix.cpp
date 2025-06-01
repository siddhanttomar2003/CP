class Solution {
public:
    int cal_mini(vector<vector<int>>&grid,int i, int j ,int k){
        priority_queue<int>q;
        set<int>st;
         for(int i2=i;i2<=i+k-1;i2++){
            for(int j2=j;j2<=j+k-1;j2++){
                int num=grid[i2][j2];
                if(st.find(num)==st.end()){
                 q.push(grid[i2][j2]);
                 st.insert(num);
                }
            }
         }
         int mini=1e9;
         if(q.size()==1)return 0;
         while(!q.empty() && q.size()>=2){
            int num1=q.top();
            q.pop();
            mini=min(mini,num1-q.top());
         }
         return mini;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>>ans;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            if(i+k-1<n){
            vector<int>temp;
            for(int j=0;j<m;j++){
                if(i+k-1<n && j+k-1<m){
                    temp.push_back(cal_mini(grid,i,j,k));
                }
            }
            ans.push_back(temp);
            }
        }
        return ans;
    }
};