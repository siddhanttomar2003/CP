class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
          map<int,int>mp;
          for(int i=0;i<arr.size();i++){
             mp[arr[i]]++;
          }
          if(mp[0]>=2){
            return true;
          }
          mp.erase(0);
          for(int i=0;i<arr.size();i++){
            if(mp.find(2*arr[i])!=mp.end()){
                return true;
            }
          }
          return false;
    }
};