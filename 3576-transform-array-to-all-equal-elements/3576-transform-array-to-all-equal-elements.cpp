class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
          int n=nums.size();
          int count1=0;
          vector<int>pos1,pos2;
          for(int i=0;i<n;i++){
              if(nums[i]==1){
                count1++;
                pos1.push_back(i);
              }
              else pos2.push_back(i);
          }

          int count11=n-count1;
          if(count1&1 && count11&1)return false;
          int ans=1e9;
          if(count1%2==0 && count1>0){
            int op1=0;
            for(int i=0;i<pos1.size()-1;i+=2){
                op1+=pos1[i+1]-pos1[i];
            }
            ans=min(ans,op1);
          }
          if(count11%2==0 && count11>0){
            int op2=0;
            for(int i=0;i<pos2.size()-1;i+=2){
                op2+=pos2[i+1]-pos2[i];
            }
            ans=min(ans,op2);
          }
          if(ans<=k)return true;
          return false;
    }
};