class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=1;
        map<int,int>mp;
        for(int i=0;i<n;i++){
           int s=nums[i]-k;
           int e=nums[i]+k;
           mp[s]++;
           mp[e+1]--;
        }
        vector<int>l_sweep;
        int c=0;
        for(auto it:mp){
           if(c==0){
            l_sweep.push_back(it.second);
            c++;
           }
           else {
            l_sweep.push_back(l_sweep.back()+it.second);
           }
        }
        for(int i=0;i<l_sweep.size();i++){
            maxi=max(maxi,l_sweep[i]);
        }
       
        return maxi;

        
    }
};