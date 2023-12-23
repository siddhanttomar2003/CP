class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0;
        int y=0;
        set<pair<int,int>>s;
        pair<int,int>pa;
        pa.first=x;pa.second=y;
        s.insert(pa);
        for(int i=0;i<path.size();i++){
            if(path[i]=='N')y++;
            else if(path[i]=='S')y--;
            else if(path[i]=='W')x--;
            else x++;
            pair<int,int>p;
            p.first=x;p.second=y;
            if(s.find(p)!=s.end())return true;
            s.insert(p);
            
        }
        return false;
    }
};