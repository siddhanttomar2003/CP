class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
    set<string>s;
    for(int i=0;i<paths.size();i++){
        s.insert(paths[i][0]);
    }
    vector<string>v;
    for(int i=0;i<paths.size();i++){
        v.push_back(paths[i][0]);
        v.push_back(paths[i][1]);
    }
    string ans="";
    for(int i=0;i<v.size();i++){
        if(s.find(v[i])==s.end()){ans=v[i];
        break;
        }
    }
    return ans;



    
      
    }
};