class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int n=arr.size();
         int low=0,high=n-1;
         while(low<=high){
            int mid=low+(high-low)/2;
            int missing=arr[mid]-(mid+1);
            if(missing>=k){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
         }  
         if(high<0)return k; 
         int rem=k-(arr[high]-(high+1));
         return arr[high]+rem;
        
    }
};