class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=possible.size();
        vector<int>suffix(n);
        int sum=0;
        for(int i=n-1;i>=0;i--){
            if(possible[i]==1)sum-=1;
            else sum+=1;
            suffix[i]=sum;
        }
        int pos=-1;
        int curr=0;
        for(int i=0;i<n-1;i++){
            if(possible[i]==1)curr++;
            else curr--;
            if(curr>suffix[i+1]){
                pos=i;break;
            }
        }
        return pos+1;
    }
};