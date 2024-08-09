class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<int>>prefixr;

        for(int i=0;i<n;i++){
            long long sum=0;
            vector<int>temp(m+1);
            temp[0]=0;
            for(int j=0;j<m;j++){
                 temp[j+1]=temp[j]+grid[i][j];
            }
            prefixr.push_back(temp);
        }
     
        vector<vector<int>>prefixc;
        for(int j=0;j<m;j++){
            vector<int>temp(n+1);
            temp[0]=0;
            for(int i=0;i<n;i++){
                temp[i+1]=temp[i]+grid[i][j];
            }
            prefixc.push_back(temp);
        }
           for(int i=0;i<prefixc.size();i++){
            for(int j=0;j<prefixc[i].size();j++){
                cout<<prefixc[i][j]<<" ";
            }
            cout<<endl;
        }
        int count=0;
        // int check=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                //first row
                // if(check==0){
                int sum_fr=prefixr[i][j+3]-prefixr[i][j];
                // second row
                int sum_sr=prefixr[i+1][j+3]-prefixr[i+1][j];
                // third_row
                int sum_tr=prefixr[i+2][j+3]-prefixr[i+2][j];
                // first col
                int sum_fc=prefixc[j][i+3]-prefixc[j][i];
                //second col
                int sum_sc=prefixc[j+1][i+3]-prefixc[j+1][i];
                // third col
                int sum_tc=prefixc[j+2][i+3]-prefixc[j+2][i];
                // first diagonal
                int sum_fd=prefixr[i][j+1]-prefixr[i][j]+prefixr[i+1][j+2]-prefixr[i+1][j+1]+prefixr[i+2][j+3]-prefixr[i+2][j+2];
                //second diagonal
                int sum_sd=prefixr[i][j+3]-prefixr[i][j+2]+prefixr[i+1][j+2]-prefixr[i+1][j+1]+prefixr[i+2][j+1]-prefixr[i+2][j];
                unordered_set<int>st;
                if(sum_fr==sum_sr && sum_sr==sum_tr && sum_tr==sum_fc &&  sum_fc==sum_sc && sum_sc==sum_tc && sum_tc==sum_fd && sum_fd==sum_sd){
                   st.insert(prefixr[i][j+1]-prefixr[i][j]);
                   st.insert(prefixr[i][j+2]-prefixr[i][j+1]);
                   st.insert(prefixr[i][j+3]-prefixr[i][j+2]);
                   st.insert(prefixr[i+1][j+1]-prefixr[i+1][j]);
                   st.insert(prefixr[i+1][j+2]-prefixr[i+1][j+1]);
                   st.insert(prefixr[i+1][j+3]-prefixr[i+1][j+2]);
                   st.insert(prefixr[i+2][j+1]-prefixr[i+2][j]);
                   st.insert(prefixr[i+2][j+2]-prefixr[i+2][j+1]);
                   st.insert(prefixr[i+2][j+3]-prefixr[i+2][j+2]);
                   if(st.find(1)!=st.end() && st.find(2)!=st.end() && st.find(3)!=st.end() && st.find(4)!=st.end() &&st.find(5)!=st.end() && st.find(6)!=st.end() && st.find(7)!=st.end() && st.find(8)!=st.end() && st.find(9)!=st.end() )count++;
                }
          
                
                
            }
        }
        return count;
    }
};