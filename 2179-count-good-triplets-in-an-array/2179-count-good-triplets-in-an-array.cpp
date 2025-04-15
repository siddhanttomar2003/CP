typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll ans=0;
        ordered_set st1,st2;
        int n=nums2.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }
        st1.insert(mp[nums1[0]]);
        vector<ll>left(n,0),right(n,0);
        for(int i=1;i<n-1;i++){
           left[i]=st1.order_of_key(mp[nums1[i]]);
           st1.insert(mp[nums1[i]]);
        }
        // for(int i=0;i<n;i++)cout<<left[i]<<" ";
        // cout<<endl;
        st2.insert(mp[nums1[n-1]]);
        for(int i=n-2;i>0;i--){
            right[i]=st2.size()-st2.order_of_key(mp[nums1[i]]+1);
            st2.insert(mp[nums1[i]]);
            ans+=(right[i]*left[i]);
        }
        // for(int i=0;i<n;i++)cout<<right[i]<<" ";
        // cout<<endl;
        return ans;
    }
};