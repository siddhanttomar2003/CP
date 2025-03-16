class Solution {
public:
    bool check(long long m, vector<int>&r, int c){
       long long curr=0;
       for(int i=0;i<r.size();i++){
        curr+=(sqrtl(m/(r[i]*1LL)));
       }
       return curr>=c;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        long long t=cars*1LL*cars*1LL;
        long long maxi=*max_element(ranks.begin(),ranks.end());
        long long l=1,r=maxi*t;
        while(l<=r){
            long long m=l+(r-l)/2;
            if(check(m,ranks,cars))
                r=m-1;
            else l=m+1;
        }
        return l;
    }
};