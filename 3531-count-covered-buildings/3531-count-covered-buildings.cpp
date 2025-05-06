class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int,set<int>>mp_x,mp_y;
        for(auto it:buildings){
            mp_x[it[0]].insert(it[1]);
            mp_y[it[1]].insert(it[0]);
        }
        int count=0;
        for(auto it:buildings){
            int x=it[0];
            int y=it[1];
            auto it1=mp_x[x].upper_bound(y);
            bool check=true;
            if(it1==mp_x[x].end())check=false;
            auto it2=mp_x[x].begin();
            if(*it2==y)check=false;
            auto it3= mp_y[y].upper_bound(x);
            if(it3==mp_y[y].end())check=false;
            auto it4= mp_y[y].begin();
            if(*it4==x)check=false;
            if(check)count++;
        }
        return count;
    }
};