vector<int> G ;
typedef long long ll;
void gpd(int n) {
    G.assign(n + 1, 1);
    G[0] = G[1] = 1;
    for (ll i = 2; i*i <= n; i++)
        for (ll j = i * i; j <= n; j += i)
          if(G[j]==1){
            G[j]=i;
          }
}

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op=0;
        int n=nums.size();
        int curr_min=nums[n-1];
         int maxi=*max_element(nums.begin(),nums.end());
         gpd(maxi+1);
        cout<<G[25]<<" ";
        for(int i=n-2;i>=0;i--){
            if(nums[i]>curr_min){
                int num=nums[i];
                while(G[num]!=1 && num>curr_min){
                    num=G[num];
                    op++;
                }
                if(num>curr_min)return -1;
                curr_min=min(curr_min,num);
            }
            curr_min=min(curr_min,nums[i]);
        }
        return op;
    }
};