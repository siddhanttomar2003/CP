class Solution {
public:
    int numTeams(vector<int>& nums) {
        int n=nums.size();
     vector<int>smaller(n+1,0);
     vector<int>larger(n+1,0);
     vector<int>smaller2(n+1,0);
     vector<int>larger2(n+1,0);
     for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                smaller[i]++;
            }
            else {
                larger2[i]++;
            }
        }
     }
     for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(nums[j]>nums[i]){
                larger[i]++;
            }
            else smaller2[i]++;
        }
     }
     int ans=0;
     for(int i=0;i<n;i++){
        cout<<smaller[i]<<" "<<larger[i]<<endl;
            if(smaller[i]>=1 &&larger[i]>=1){
                ans+=(smaller[i]*larger[i]);
            }
            if(smaller2[i]>=1 && larger2[i]>=1){
                ans+=(smaller2[i]*larger2[i]);
            }
     }
     return ans;
    }
};