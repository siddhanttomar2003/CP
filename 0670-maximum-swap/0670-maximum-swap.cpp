class Solution {
public:
    int maximumSwap(int num) {
        string a =  to_string(num);
        char maxi = '0';
        int ind_e = -1;
        int ind_s = -1;
        int last = -1;
        for(int i = a.size() - 1; i >= 0; i--){
            if(a[i] < maxi){
                ind_s = i;
                last = ind_e;
            }
            else if(a[i] > maxi){
                maxi = a[i];
                ind_e = i;
            }
        }
        if(ind_s != -1 && last != -1){
            swap(a[ind_s] , a[last]);
        }
        int ans = stoi(a);
        return ans;
    }
};