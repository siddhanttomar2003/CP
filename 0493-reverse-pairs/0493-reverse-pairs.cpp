class Solution {
public:
     int merge(int low,int high,int mid,vector<int> &nums){
        int count=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            if( right<=high && i<=mid && nums[i]>2*1ll*nums[right]*1ll ){
         while( right<=high && i<=mid && nums[i]>2*1ll*nums[right]*1ll ){
            count+=(mid-i+1);
            right++;
         }
        }
        }
        vector<int>temp;
        int m=mid+1;
        int l=low;
        while(low<=mid && m<=high){
            if(nums[low]<=nums[m]){
                temp.push_back(nums[low]);
                low++;
            }
            else {
                temp.push_back(nums[m]);
                m++;
            }
        }
        while(low<=mid){
            temp.push_back(nums[low]);low++;
        }
        while(m<=high){
            temp.push_back(nums[m]);m++;
        }
        int j=0;
        for(int i=l;i<=high;i++){
            nums[i]=temp[j];j++;
        }
        return count;

     }
    int mergesort(int low,int high, vector<int> &nums){
        if(low>=high)return 0;
        int mid=low+(high-low)/2;
        int count=0;
        count+=mergesort(low,mid,nums);
        count+=mergesort(mid+1,high,nums);
        count+=merge(low,high,mid,nums);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int i=0;
        int e=nums.size()-1;
        return mergesort(i,e,nums);
    }
};