class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>temp(26,0);
        for(int i=0;i<allowed.size();i++){
            temp[allowed[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
        bool check=true;
          for(int j=0;j<words[i].size();j++){
            if(temp[words[i][j]-'a']==0)check=false;
          }
          if(check)ans++;
        }
        return ans;
    }
};