class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0;
        int j=arr.size()-1;
        int low=0;
        int last_rem=0;
        int last=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            int rem=arr[mid]-(mid+1);
            if(rem<k){
                i=mid+1;
                last=arr[mid];
                low=mid;
                last_rem=rem;
            }
            else {
              j=mid-1;
            }
        }
        return last+(k-last_rem);
       
    }
};