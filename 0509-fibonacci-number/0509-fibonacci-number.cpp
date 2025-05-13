class Solution {
public:
    vector<vector<int>> mul(vector<vector<int>>&a, vector<vector<int>>&b){
        vector<vector<int>>store(2,vector<int>(2,0));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    store[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        return store;
    }
    vector<vector<int>> find_ans(vector<vector<int>>&s,int pow){
        vector<vector<int>>res={{1,0},{0,1}};// as we do in simple binary exponentiation initialize result with res=1, 
        while(pow>0){
            if(pow&1)res=mul(res,s);
            s=mul(s,s);
            pow/=2;
        }
        return res;
    }
    int fib(int n) {
        // using matrix multiplication
        if(n==0 || n==1)return n;
        vector<vector<int>>state_matrix={{1,1},{1,0}};
        // because see it like this [f(n),f(n-1)]=[[1,1],[1,0]]*[f(n-1),f(n-2)]
        // after performing lhs , f(n)=f(n-1)+f(n-2), f(n-1)=f(n-1),
        // and if raise this power to n-1 of the state matrix we can find nth number 
        // as raising the power vaala part can be easily solved using binary exponentiation 
        // so tc O(logn) pdega sirf
        vector<vector<int>>res=find_ans(state_matrix,n-1);
        return res[0][0];
    }
};