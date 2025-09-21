class MovieRentingSystem {
public:
    set<vector<int>>rem; // for report
    map<int,set<pair<int,int>>>mp; // mapping for movie -> price, shop;
    map<pair<int,int>,int>m_p;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &it : entries){
            mp[it[1]].insert({it[2], it[0]});
            // rem.insert({it[2], it[1], it[0]});
            m_p[{it[0], it[1]}] = it[2];
        }
    }
    vector<int> search(int movie) {
        vector<int>ans;
        int count = 0;
        for(auto it : mp[movie]){
            if(count == 5)break;
            ans.push_back(it.second);
            count++;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int p = m_p[{shop, movie}];
        rem.insert({p, shop, movie});
        mp[movie].erase({p, shop});
    }
    
    void drop(int shop, int movie) {
        int p = m_p[{shop, movie}];
        mp[movie].insert({p, shop});
        rem.erase({p, shop, movie});
    }
    
    vector<vector<int>> report() {
        int count = 0;
        vector<vector<int>>ans;
        for(auto &it : rem){
            if(count == 5)break;
            ans.push_back({it[1], it[2]});
            count++;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */