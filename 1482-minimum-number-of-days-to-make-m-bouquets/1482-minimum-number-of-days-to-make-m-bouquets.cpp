class Solution {
public:
    int check(vector<int> bloomDay, int mid, int m, int k) {
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid)
                bloomDay[i] = '#';
        }
        int count = 0;
        int fav_count = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] == '#') {
                count++;
                if (count == k) {
                    fav_count++;
                    count = 0;
                }
            } else
                count = 0;
        }
        if(fav_count>=m)return 1;
        else return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long mm=m;
        long long kk=k;
        if(mm*kk>bloomDay.size())return -1;
        
        int min_days = *min_element(bloomDay.begin(), bloomDay.end());
        int max_days = *max_element(bloomDay.begin(), bloomDay.end());
        // answer will be between max and minimum;
        // now we have to just find the number between them
        int i = min_days;
        int e = max_days;
        // we know that if at a particular day if it is not satisfying then
        // the days before this day it will not automatically not satisfy
        int ans = max_days;
        while (i <= e) {
            int mid = i + (e - i) / 2;
            int f_ans = check(bloomDay, mid, m, k);
            if(f_ans==1){
                ans=min(ans,mid);
                e=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};