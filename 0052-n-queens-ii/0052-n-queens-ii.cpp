class Solution {
public:
    vector<int>row;
    map<int,int>right_diagonal, left_diagonal;
    int cal(int n, int i){
        if(i == n)return 1;
        int w = 0;
        for(int j = 0; j < n; j++){
            if(!row[j] && right_diagonal.find(i - j) == right_diagonal.end() && left_diagonal.find(i + j) == left_diagonal.end()){
                row[j] = 1;
                right_diagonal[i - j]++;
                left_diagonal[i + j]++;
                w += cal(n, i + 1);
                row[j] = 0;
                right_diagonal.erase(i - j);
                left_diagonal.erase(i + j);
            }
        }
        return w;
    }
    int totalNQueens(int n) {
        row.resize(n + 1, 0);
        return cal(n, 0);
    }
};