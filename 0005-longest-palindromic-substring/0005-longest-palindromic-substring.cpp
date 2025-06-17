class Solution {
public:
    int isPal[1001][1001];
    bool build(string &s, int i, int j){
        if(j<i)return true;
        if(i==j) return isPal[i][j]=true;
        if(isPal[i][j]!=-1)return isPal[i][j];
        if(s[i]==s[j]){
            isPal[i][j]=build(s,i+1,j-1);
        }
        else {
            isPal[i][j]=0;
        }
        build(s,i+1,j);
        build(s,i,j-1);
        return isPal[i][j];
    }
    string longestPalindrome(string s) {
        int n=s.size();
        memset(isPal,-1,sizeof(isPal));
        build(s,0,n-1);
        int len=0;
        int start=-1,end=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isPal[i][j] && j>=i && j-i+1>len ){
                    len=j-i+1;
                    start=i;
                    end=j;
                }
            }
        }
        string ans="";
        for(int i=start;i<=end;i++)ans+=s[i];
        return ans;
    }
};