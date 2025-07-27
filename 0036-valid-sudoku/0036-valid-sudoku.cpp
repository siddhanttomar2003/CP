class Solution {
public:
    vector<vector<int>>rows, cols, boxes;
    
    bool isValidSudoku(vector<vector<char>>& board) {
        rows.assign(10, vector<int>(10, 0));
        cols.assign(10, vector<int>(10, 0));
        boxes.assign(10, vector<int>(10, 0));
        bool check = true;
        for(int i = 0; i < 3; i++){
            for(int j = 0 ; j < 3; j++){
                    int s_r = i * 3;
                    int s_c = j * 3;
                    int box = i * 3 + j;
                    for(int k = s_r; k < s_r + 3; k++){
                        for(int l = s_c; l < s_c + 3; l++){
                            if(board[k][l] == '.')continue;
                            int val = board[k][l] - 48;
                            boxes[box][val]++;
                            if(boxes[box][val] == 2)return false;
                            rows[k][val]++;
                            if(rows[k][val] == 2)return false;
                            cols[l][val]++;
                            if(cols[l][val] == 2)return false;
                        }
                    }
            }
        }
        return true;
    }
};