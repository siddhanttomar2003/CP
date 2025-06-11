class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<char>>&b){
        return i>=0 && i<n && j>=0 && j<m && b[i][j]!='#';
    }
    void cal(int i, int j, vector<vector<char>>&b, string &curr, unordered_set<string>&ans, int len,unordered_map<string,int>&mp){
         if(len>=10)return;

         int delRow[]={-1,0,1,0};
         int delCol[]={0,1,0,-1};
         int n=b.size(),m=b[0].size();
         curr+=b[i][j];
         b[i][j]='#';
         if(mp.find(curr)!=mp.end())ans.insert(curr);
         for(int k=0;k<4;k++){
            int n_r=i+delRow[k];
            int n_c=j+delCol[k];
            if(isValid(n_r,n_c,n,m,b)){
                cal(n_r,n_c,b,curr,ans,len+1,mp);
            }
         }
         b[i][j]=curr.back();
         curr.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string>ans;
        int n=board.size(),m=board[0].size();
        unordered_map<string,int>mp;
        for(auto it:words)mp[it]++;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string curr="";
                cal(i,j,board,curr,ans,0,mp);
            }
        }
        vector<string>f_ans;
        for(auto it:ans)f_ans.push_back(it);
        return f_ans;
    }
};