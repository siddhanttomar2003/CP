class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        if(n<m){
            swap(text1, text2);
            swap(n, m);
        }
        vector<int> prev(m+1,0), current(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) {
                if(text1[i-1]==text2[j-1]){
                    current[j]=1+prev[j-1];
                }else{
                    current[j]=max(current[j-1],prev[j]);
                }
            }
        swap(prev, current);
        }
    return prev[m];
    }
};