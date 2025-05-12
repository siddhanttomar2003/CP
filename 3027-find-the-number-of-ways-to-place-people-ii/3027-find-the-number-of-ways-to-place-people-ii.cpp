#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
#define ordered_set tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long ll;
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
         sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];      
    });
        int n = points.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            ll y1 = points[i][1];
            ll maxi=-1e18;
            for (int j = i+1; j < n; j++) {
                ll y2 = points[j][1];
                if (y2 <= y1 ) {
                   if(maxi<y2)count++;
                   maxi=max(maxi,y2);
                }
            }
        }
        return count;
    }
};