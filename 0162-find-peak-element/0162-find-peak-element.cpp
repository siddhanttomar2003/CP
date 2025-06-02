class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int l=0,h=n-1;
        if(n==1)return 0;
        while(l<=h){
            int m= l+(h-l)/2;
            if(m-1>=0 && arr[m]>arr[m-1] && m+1<n &&  arr[m]>arr[m+1])return m;
            if(m==0 && arr[m]>arr[m+1])return m;
            if(m==n-1 && arr[m]>arr[m-1])return m;
            if(m-1>=0 && arr[m]>arr[m-1])l=m+1;
            else {
                if(m==0)l=m+1;
                else h=m-1;
            }
        }
        return -1;
    }
};