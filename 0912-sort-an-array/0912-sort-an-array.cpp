class Solution {
public:
     void combine(vector<int> &nums,int s,int mid,int e){
        int i=s;
        int m=mid;
        int j=mid+1;
        int n=e;
        vector<int>temp;
        while(i<=m&&j<=n){
            if(nums[i]>nums[j]){
                temp.push_back(nums[j]);
                j++;
            }
            else if(nums[j]>nums[i]){
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                j++;i++;
            }
        }
        while(i<=m){
            temp.push_back(nums[i]);i++;
        }
        while(j<=n){
            temp.push_back(nums[j]);j++;
        }
        for(int i=s;i<=e;i++){
            nums[i]=temp[i-s];
        }
     }
    void mergesort(vector<int>&nums,int s, int e){
        if(s>=e)return;
        int mid=s+(e-s)/2;
        mergesort(nums,s,mid);
        mergesort(nums,mid+1,e);
        combine(nums,s,mid,e);

    }
    vector<int> sortArray(vector<int>& nums) {
        int s=0;int e=nums.size()-1;
        mergesort(nums,s,e);
        return nums;
    }
};