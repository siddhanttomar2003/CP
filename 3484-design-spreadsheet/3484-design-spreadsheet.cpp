class Spreadsheet {
public:
    vector<vector<int>>grid;
    Spreadsheet(int rows) {
        grid.resize(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int r=cell[1]-49;
        int c=cell[0]-65;
        grid[r][c]=value;
    }
    
    void resetCell(string cell) {
         int r=cell[1]-49;
        int c=cell[0]-65;
        grid[r][c]=0;
    }
    
    int getValue(string formula) {
        int val1=0;
        int val2=0;
        string fir="",sec="";
        int i=1;
        if(formula[1]>=65 && formula[1]<=90){
             int c=formula[1]-65;
             i=2;
             while(formula[i]!='+'){
                fir+=formula[i];i++;
             }
             int r=stoi(fir)-1;
             val1=grid[r][c];
        }
        else {
              while(formula[i]!='+'){
                fir+=formula[i];i++;
             }
             val1=stoi(fir);
        }
        i++;
        if(formula[i]>=65 && formula[i]<=90){
            int c=formula[i]-65;
            i++;
            while(i<formula.size()){
                sec+=formula[i];i++;
            }
            int r=stoi(sec)-1;
            val2=grid[r][c];
        }
        else {
            while(i<formula.size()){
                sec+=formula[i];
                i++;
            }
            val2=stoi(sec);
        }
        return val1+val2;

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */