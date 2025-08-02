class Solution {
public:
    typedef long long ll;
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<ll,ll>mp1, mp2;
        ll mini = *min_element(basket1.begin(), basket1.end());
        mini = min(mini, (ll)*min_element(basket2.begin(), basket2.end()));
        for(auto it : basket1){
            mp1[it]++;
        }
        for(auto it : basket2)mp2[it]++;
        for(auto it : basket1){
            if(mp2.find(it) != mp2.end()){
                mp2[it]--;
                if(mp2[it] == 0)mp2.erase(it);
                mp1[it]--;
                if(mp1[it] == 0)mp1.erase(it);
            }
        }
        for(auto it : basket2){
            if(mp1.find(it) != mp1.end() && mp2.find(it) != mp2.end()){
                mp1[it]--;
                if(mp1[it] == 0)mp1.erase(it);
                mp2[it]--;
                if(mp2[it] == 0)mp2.erase(it);
            }
        }
        ll sum = 0;
        // for(auto it : mp1) cout << it.first << " " << it.second << endl;
        // cout << endl;
        // for(auto it : mp2)cout << it.first << " " << it.second << endl;
        vector<ll>f1, f2;
        for(auto it : mp1){
            if(it.second & 1)return -1;
            for(ll i = 0; i < it.second; i++)
            f1.push_back(it.first);
        }
        for(auto it : mp2){
            if(it.second & 1)return -1;
            for(ll i = 0; i < it.second; i++)
            f2.push_back(it.first);
        }
        f1.insert(f1.end(), f2.begin(), f2.end());
        sort(f1.begin(), f1.end());
        for(ll i = 0; i < f1.size() / 2; i+=2){
            sum += min(2 * mini, f1[i]);
        }
        return sum;
    }
};