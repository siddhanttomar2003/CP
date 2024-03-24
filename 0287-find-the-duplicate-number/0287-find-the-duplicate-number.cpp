class Solution {
public:
    int Smaller_than_mid(vector<int>&nums,int &mid){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid)count++;
        }
        return count;
    }
    int findDuplicate(vector<int>& nums) {
       // binary search on answers
       // we know that the answer will always be in the range of 1->n
       int s=1;
       int e=nums.size()-1;
       while(s<e){
        int mid=s+(e-s)/2;
        int count=Smaller_than_mid(nums,mid);
        if(count>mid){// means answer lies on the left side including mid
        e=mid;
        }
        else s=mid+1;
       }
       return e;
    }
   
};
