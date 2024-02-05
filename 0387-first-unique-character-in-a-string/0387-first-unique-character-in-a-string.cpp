class Solution {
public:
    int firstUniqChar(string s) {
       unordered_map<char,vector<int>>mp;
       for(int i=0;i<s.length();i++){
           mp[s[i]].push_back(i);
       }
       int ans=INT_MAX;
       for(auto it:mp){
           if(it.second.size()==1){
               if(ans>it.second[0]){
                   ans=it.second[0];
               }
           }
       }
       if(ans==INT_MAX)return -1;
       else return ans;


      
    }
};