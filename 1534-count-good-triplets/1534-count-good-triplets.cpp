class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        // sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n-2;i++){
          for(int j=i+1;j<n-1;j++){
             for(int k=j+1;k<n;k++){
                if(abs(arr[j]-arr[i])<=a && abs(arr[k]-arr[j])<=b && abs(arr[k]-arr[i])<=c)ans++;
             }
          }
        }
        return ans;
    }
};