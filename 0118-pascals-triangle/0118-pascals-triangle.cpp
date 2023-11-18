class Solution {
public:
     long long factorial(int i,int j){
         if(i==0||j==0||i==j)return 1;
           int m=min(j,i-j);
           long long result=1;
         for(int k=0;k<m;k++){
         result=result*(i-k);
         result=result/(k+1);
         }
         return result;
         
     }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
       for(int i=0;i<numRows;i++){
           vector<int>v;
           for(int j=0;j<=i;j++){
               long long number=factorial(i,j);
               v.push_back(number);
           }
           ans.push_back(v);
       }
        return ans;
    }
};