class Solution {
public:
    long long maxWeight(vector<int>& p) {
       int n=p.size();
       sort(p.begin(),p.end());
       long long ans=0;
       int curr=0;
       int req=n/4;
       int odd=n-1;
       vector<int>vis(n,0);
       for(int i=n-1;i>=0;i--){
         if(curr%2==0){
           while(odd>=0 && vis[odd]){
            odd--;
           } 
           ans+=p[odd];
           odd--;
         }
         else {
            if(i-1>=0){
                ans+=p[i-1];
                vis[i-1]=1;
            }
         }
         curr++;
         if(curr==req)break;
       }
       return ans;
    }
};