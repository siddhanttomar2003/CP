class Solution {
public:
    const int m=1e9+7;
    vector<vector<int>> mul(vector<vector<int>>&s,vector<vector<int>>&r,int n1,int m1,int n2,int m2){
        vector<vector<int>>res(n1,vector<int>(m2,0));
        for(int i=0;i<n1;i++){
            for(int j=0;j<m2;j++){
                for(int k=0;k<m1;k++){
                    res[i][j]=(res[i][j]+(s[i][k]*r[k][j])%m)%m;
                }
            }
        }
        return res;
    }
    vector<vector<int>> fast_pow(vector<vector<int>>&s,int t){
        vector<vector<int>>res(26,vector<int>(26,0));
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j)res[i][j]=1;
            }
        }
        while(t>0){
            if(t&1){
                res=mul(res,s,26,26,26,26);
            }
            s=mul(s,s,26,26,26,26);
            t>>=1;
        }
        return res;

    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // similiar to fibnoacci number in which we know that 
        // the current number will depend on the past two number 
        // similiary in this we know that each character will be changed
        // to according to nums vaala array
        // building state matrix first for this
        vector<vector<int>>state(26,vector<int>(26,0));
        // here state[i] will denote on which will it change in one transformation
        // so to find out after t transformation how will this look 
        // we simply need to use fast pow , matrix exponentiation
        for(int i=0;i<26;i++){
            for(int j=i+1;j<=i+nums[i];j++){
                state[i][j%26]=1;
            }
        }
        vector<vector<int>>res= fast_pow(state,t);
        // now we just need to multiply this final state for the freq of char in s
        vector<vector<int>>f(1,vector<int>(26,0));
        for(char it:s)f[0][it-'a']++;
        vector<vector<int>>f_ans=  mul(f,res,1,26,26,26);
        int ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+f_ans[0][i])%m;
        }
        return ans;
    }
};