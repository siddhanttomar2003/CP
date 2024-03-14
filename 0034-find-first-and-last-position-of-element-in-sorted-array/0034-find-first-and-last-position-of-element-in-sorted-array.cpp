class Solution {
public:
     int last_occurence(vector<int> &nums,int target){
        int a=-1;
        int i=0;int e=nums.size()-1;
        while(i<=e){
            int mid=i+(e-i)/2;
            if(nums[mid]<=target){
                if(nums[mid]==target){
                    a=mid;                  
                }
                i=mid+1;
            }
            else e=mid-1;
        }
        return a;
     }
    int first_occurence(vector<int> &nums,int target){
        int a=-1;
        int i=0;int e=nums.size()-1;
        while(i<=e){
            int mid=i+(e-i)/2;
            if(nums[mid]>=target){
                e=mid-1;
                if(nums[mid]==target)a=mid;
            }
            else i=mid+1;
        }
        return a;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=first_occurence(nums,target);
        int b=last_occurence(nums,target);
        return {a,b};

    }
};