class Solution {
public:
unordered_map<long long, int> mp;
    void fill(vector<long long>&temp, long long s, int n){
        if(n==0) return;
        if(s>=1e12) return;
        if(mp[s]) return;
        mp[s]=1;
        temp.push_back(s);

        fill(temp,s*2LL,n-1);
        fill(temp,s*3LL,n-1);
        fill(temp,s*5LL,n-1);
    }
    int nthUglyNumber(int n) {
        vector<long long >temp;
        fill(temp,1,n);
        temp.push_back(1);
        sort(temp.begin(),temp.end());
        return temp[n];
    }
};