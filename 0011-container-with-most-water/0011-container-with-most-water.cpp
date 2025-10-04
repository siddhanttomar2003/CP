class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int low = 0, high = n - 1;
        int maxi = 0;
        while(low < high){
            int temp = min(h[low], h[high]);
            int curr = (high - low) * temp;
            if(curr > maxi)maxi = curr;
            if(h[low] < h[high])low++;
            else high --;
        }
        return maxi;
    }
};