class Solution {
public:
     vector<int> generateRow(int row){
        vector<int>ans;
        int num=1;
        ans.push_back(num);
        for(int j=1;j<row;j++){
            num=num*(row-j);
            num=num/(j);
            ans.push_back(num);
        }
        return ans;
         
     }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
     for(int i=1;i<=numRows;i++){
         ans.push_back(generateRow(i));
     }
        return ans;
    }
};