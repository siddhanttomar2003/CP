class Solution {
public:
    typedef long long ll;
    bool reorderedPowerOf2(int n) {
        map<string,int>mp;
        ll i = 0;
        while(pow(2LL, i) <= 1e9){
            string num = to_string((int)pow(2LL, i));
            i++;
            // cout << num << endl;
            sort(num.begin(), num.end());
            mp[num]++;
        }
        string a = to_string(n);
        sort(a.begin(), a.end());
        if(mp.find(a) != mp.end())return true;
        return false;

    }
};