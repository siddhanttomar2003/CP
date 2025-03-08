class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n=nums.size();
        vector<int>line_sweep(n+1,0);
        for(int i=0;i<n;i++){
            int num=nums[i];
            int curr_index=i;
            int maxi_index=num;
            int mini_index=0;
            int start_k=-1,end_k=-1;
            if(num<=curr_index){
              start_k=0;
              end_k=curr_index-num;
              line_sweep[start_k]++;
              line_sweep[end_k+1]--;
              int dis=n-curr_index;
              start_k=n-dis;
              line_sweep[start_k]++;
              line_sweep[n]--;
            }
            else {
               int dis=n-curr_index;
               start_k=n-dis;
               int dis2=num-curr_index;
               end_k=n-dis2;
               line_sweep[start_k]++;
               line_sweep[end_k+1]--;
            }

        }
        for(int i=1;i<=n;i++){
            line_sweep[i]+=line_sweep[i-1];
        }
        int maxi=0;
        int ans=0;
        for(int i=0;i<=n;i++){
            if(line_sweep[i]>maxi){
                maxi=line_sweep[i];
                ans=i;
            }
        }
        return ans;
    }
};