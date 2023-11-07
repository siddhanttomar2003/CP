class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
          vector<int>time(dist.size());
          for(int i=0;i<dist.size();i++)
          {
              if (dist[i] % speed[i] != 0)
              time[i]=dist[i]/speed[i]+1;
              else  time[i]=dist[i]/speed[i];
          }
          sort(time.begin(),time.end());
           int count=0;

        for(int i=0;i<time.size();i++){
               time[i]-=i;
               if(time[i]<=0)break;
               count++;
        }
          return count;
            

    }
};