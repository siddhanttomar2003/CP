class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr.size()==1){
            int mis=arr[0]-1;
            if(k<=mis)return k;
            return arr[0]+k-mis;
        }
        int mini=0;
        int i=0;
        int e=arr.size()-1;
        int last=0;
        while(i<=e){
         int mid=i+(e-i)/2;
         int rem=arr[mid]-(mid+1);
         if(rem>=k)e=mid-1;
         else {
            mini=max(mini,rem);
            last=arr[mid];
            i=mid+1;
         }
        }
        return last+(k-mini);
    }
};