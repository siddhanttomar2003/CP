class Solution {
public:
    int cal(vector<int> &piles,int &mid, int &h){
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%mid==0)ans+=piles[i]/mid;
            else ans+=piles[i]/mid+1;
           if(ans>h)return -1;
        }
        if(ans==h)return 0;
        else return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int e=*max_element(piles.begin(),piles.end());
        int ans=e;
        while(i<=e){
            int mid=i+(e-i)/2;
            int ansi=cal(piles,mid,h);
             if(ansi==0){
                ans=min(ans,mid);
                e=mid-1;
             }
             else if(ansi==-1){
                i=mid+1;
             }
             else {
                ans=min(ans,mid);
                e=mid-1;
             }
        }
      return ans;
        }
};