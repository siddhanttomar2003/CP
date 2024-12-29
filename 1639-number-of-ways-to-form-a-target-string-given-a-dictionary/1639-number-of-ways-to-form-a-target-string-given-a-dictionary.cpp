class Solution {
public:
    const int m= 1e9+7;
    long long dp[1001][1001];
    long long cal(map<pair<int,char>,long long>&mp,int start, string &tar, int j, int size){
        if(j==tar.size())return 1;
        if(start==size)return 0;
        if(dp[start][j]!=-1)return dp[start][j];
        long long ways1=0,ways2=0;
        // if(dp[j]!=-1)return dp[j];
        if(mp.find({start,tar[j]})!=mp.end()){
            ways2=(mp[{start,tar[j]}]*cal(mp,start+1,tar,j+1,size))%m;
        }
        ways1=cal(mp,start+1,tar,j,size);
        return  dp[start][j]=(ways1+ways2)%m;
    }
    int numWays(vector<string>& words, string target) {
        int n=words.size();
        int n2=target.size();
        memset(dp,-1,sizeof(dp));
        int m_size=words[0].size();
        map<pair<int,char>,long long>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m_size;j++){
                mp[{j,words[i][j]}]++;
            }
        }
        return cal(mp,0,target,0,m_size);
    }
};