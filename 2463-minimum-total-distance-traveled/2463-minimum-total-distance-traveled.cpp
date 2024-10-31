typedef long long ll;
class Solution {
public:
     ll dp[101][101][101];
    ll cal(vector<int>&robot, vector<vector<int>>&factory, int i, int j, int k){
         if(i==robot.size()){
            return 0;
         }
         if(j==factory.size())return 1e12;
         if(dp[i][j][k]!=-1)return dp[i][j][k];
         ll temp1=1e12;
         if(j+1<factory.size())
         temp1=cal(robot,factory,i,j+1,factory[j+1][1]);
         ll temp2=1e12;
         if(k>0){ 
            temp2=abs(robot[i]-factory[j][0])+cal(robot,factory,i+1,j,k-1);
         }
         return dp[i][j][k]=min(temp1,temp2);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
       memset(dp,-1,sizeof(dp));
       sort(robot.begin(),robot.end());
       sort(factory.begin(),factory.end());
       return  cal(robot,factory,0,0,factory[0][1]);
    }
};