class Solution {
public:
    void recur(string s,vector<string> &ans,int i,string &temp){
     if(i==s.length()){
        ans.push_back(temp);
        return;
     }
     if(s[i]>=97){
        temp+=(char)(s[i]-32);
        recur(s,ans,i+1,temp);
        temp.pop_back();
        temp+=s[i];
        recur(s,ans,i+1,temp);
        temp.pop_back();
     }
     else if(s[i]>=65){
          temp+=(char)(s[i]+32);
          recur(s,ans,i+1,temp);
        temp.pop_back();
        temp+=s[i];
        recur(s,ans,i+1,temp);
            temp.pop_back();
     }
     else {
        temp+=s[i];
     recur(s,ans,i+1,temp);
         temp.pop_back();
     }

    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string temp="";
        recur(s,ans,0,temp);
        return ans;
    }
};