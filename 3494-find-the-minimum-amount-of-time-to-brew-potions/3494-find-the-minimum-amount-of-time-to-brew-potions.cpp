typedef long long ll;
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<ll>end_time(n+1);
        ll last=0;
        for(int i=0;i<n;i++){
            end_time[i+1]=(ll)skill[i]*mana[0]+last;
            // cout<<end_time[i+1]<<" ";
            // cout<<endl;
            last=end_time[i+1];
        }
        for(int i=1;i<m;i++){
            vector<ll>end_curr(n+1),start_curr(n+1);
            // making sure that jth wizard is avail and assigning lowest time
            for(int j=0;j<n;j++){
             start_curr[j+1]=max(end_time[j+1],end_curr[j]);
             end_curr[j+1]=start_curr[j+1]+skill[j]*mana[i];
            }
           // now making sure that we are doing continuously brewing so travelling from end 
           for(int j=n-2;j>=0;j--){
            end_curr[j+1]=start_curr[j+2];
            start_curr[j+1]=end_curr[j+1]-skill[j]*mana[i];
           }
           end_time=end_curr;
        }
        return end_time[n];

    }
};