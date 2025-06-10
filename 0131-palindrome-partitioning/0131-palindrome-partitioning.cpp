class Solution {
public:
    bool isPalendrome(string s, int start,int end){
          while(start<=end){
           if(s[start]!=s[end])return false;
            start++;end--;
          }
          return true;
    }
    void palendrome_partition(int index, vector<string>&store, vector<vector<string>>&ans,string s){
        if(index==s.length()){
            ans.push_back(store);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalendrome(s,index,i)){
                store.push_back(s.substr(index,i-index+1));
                palendrome_partition(i+1,store,ans,s);
                store.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>store;
        int index=0;
        palendrome_partition(index,store,ans,s);
        return ans;
    }
};