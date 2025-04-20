class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long n=values.size();
        vector<long long>vis(n,0);
        long long i=0;
        long long ans=0;
        while(i<n && i>=0){
         if(vis[i])break;
         if(instructions[i]=="jump"){
            vis[i]=1;
            i+=values[i];
         }
         else {
            ans+=(long long)values[i];
            vis[i]=1;
            i++;
         }
        }
        return ans;
    }
};