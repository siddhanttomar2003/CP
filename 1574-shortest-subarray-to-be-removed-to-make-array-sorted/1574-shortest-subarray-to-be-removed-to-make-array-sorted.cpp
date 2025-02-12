class Solution {
public:
       int findLengthOfShortestSubarray(vector<int>& a) {
     
        int n = a.size();
        int low = 0, high = n-1;
        
        while( low+1 < n and a[low] <= a[low+1] )
            low++;
        
        if(low == n-1) return 0;
        
        while(high > low and  a[high] >= a[high-1] )
            high--;
        
        int ans = min(n-low-1, high);
        
        int i = 0, j = high;
        
        while(i<=low and j<n)
        {
            if( a[i] <= a[j] )
            {
                ans=min(ans, j-i-1);
                i++;
            }
            else 
                j++;
        }
        
        return ans;
    }
};