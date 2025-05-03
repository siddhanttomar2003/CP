class Solution {
public:
    void buildlps(vector<int>& lps, string& p) {
        int len = 0;
        int i = 1;
        lps[0] = 0;
        while (i < p.size()) {
            if (p[i] == p[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }
    int countCells(vector<vector<char>>& grid, string pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        buildlps(lps, pattern);
        int N = grid.size(), M = grid[0].size();
        int len=N*M;
        vector<int>line_sweep1(len+1,0),line_sweep2(len+1,0);
        int k=0;
        int i=0,j=0;
        while(i<N){
            if(grid[i][j]==pattern[k]){
                k++;
                if(k==n){
                    int curr_len=i*M+j;
                    int start=curr_len-n;
                    line_sweep1[start+1]++;
                    line_sweep1[curr_len+1]--;
                    k=lps[k-1];
                }
                j++;
            }
            else {
                if(k!=0){
                    k=lps[k-1];
                }
                else j++;
            }
            if(j==M){
                j=0;
                i++;
            }
        }
        i=0,j=0;k=0;
        while(j<M){
            if(grid[i][j]==pattern[k]){
                k++;
                  if(k==n){
                    int curr_len=j*N+i;
                    int start=curr_len-n;
                    line_sweep2[start+1]++;
                    line_sweep2[curr_len+1]--;
                    k=lps[k-1];
                }
                i++;
            }
            else {
                if(k!=0)k=lps[k-1];
                else i++;
            }
            if(i==N){
                i=0;j++;
            }
        }
        for(int i=1;i<len;i++){
            line_sweep1[i]+=line_sweep1[i-1];
            line_sweep2[i]+=line_sweep2[i-1];
        }
        int ans=0;
        for(int i=0;i<len;i++){
            int r=i/M;
            int c=i%M;
            if(line_sweep1[i]>0 && line_sweep2[c*N+r]>0)ans++;
        }
        return ans;
    }
};