class Solution {
public:
    int startwithone(vector<int>nums,set<int>st0,set<int>st1){
        int count=0;
         for(int i=0;i<nums.size();i++){
             if(i%2==1){
                if(nums[i]==0)continue;
                else {
                    auto it = st0.upper_bound(i);
                    if(it == st0.end())return -1;
                    int ind = *it;
                    st0.erase(ind);
                    st1.insert(ind);
                    nums[ind]=1;
                  
                    count+=(ind-i);
                }
             }
             else {
                if(nums[i])continue;
                else {
                    auto it = st1.upper_bound(i);
                    if(it == st1.end())return -1;
                    int ind = *it;
                    st1.erase(ind);
                    st0.insert(ind);
                    nums[ind]=0;
                 
                    count+=(ind-i);
                }
             }
         }
         return count;
    }
    int startwithzero(vector<int>nums, set<int>st0, set<int>st1){
        int count=0;
         for(int i=0;i<nums.size();i++){
             if(i%2==0){
                if(nums[i]==0)continue;
                else {
                    auto it = st0.upper_bound(i);
                    if(it == st0.end())return -1;
                    int ind = *it;
                    st0.erase(ind);
                    st1.insert(ind);
                    nums[ind]=1;
                  
                    count+=(ind-i);
                }
             }
             else {
                if(nums[i])continue;
                else {
                    auto it = st1.upper_bound(i);
                    if(it == st1.end())return -1;
                    int ind = *it;
                    st1.erase(ind);
                    st0.insert(ind);
                    nums[ind]=0;
                    count+=(ind-i);
                }
             }

         }
         return count;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int count0=0,count1=0;
        set<int>st0,st1;
        for(int i=0;i<n;i++){
            nums[i]%=2;
            if(nums[i]==0){
                count0++;
                st0.insert(i);
            }
            else {
                count1++;
                st1.insert(i);
            }
        }

        if(abs(count0-count1)>1)return -1;

        int cal1=startwithzero(nums,st0,st1);
        int cal2=startwithone(nums,st0,st1);
        
        if(cal1 == -1 && cal2 == -1)return -1;
        if(cal1 == -1)return cal2;
        if(cal2 == -1)return cal1;
        return min(cal1,cal2);
    }
};