class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>temp;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        int size=temp.size();
        int median=-1,median2=-1;
        int ans=0;
        int ans2=0;
        if(size&1){
            median=temp[size/2];
        }
        else {
            median=temp[size/2-1];
            median2=temp[size/2];
        }
    
        for(int i=0;i<size;i++){
            int req=abs(median-temp[i]);
            if(req%x!=0)return -1;
            ans+=req/x;
        }
        bool flag2=true;
        if(size%2==0){
            for(int i=0;i<size;i++){
            int req=abs(median2-temp[i]);
            if(req%x!=0)flag2=false;
            ans2+=req/x;
            }
        }

        if(size&1)return ans;
        if(!flag2)return -1;
        return min(ans,ans2);

    }
};