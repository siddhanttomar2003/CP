class Solution {
public:
     void recursion(string &s,unordered_map<char,string>&mp,vector<string>&ans,int index,string &digits){
         if(index==digits.size()){
             ans.push_back(s);
             return;
         }
         string t=mp[digits[index]];
         for(int i=0;i<t.size();i++){
             s+=t[i];
             recursion(s,mp,ans,index+1,digits);
             s.pop_back();
         }
     }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string s="";
        vector<string>ans;
        if(digits.size()==0)return ans;
        int index=0;
        recursion(s,mp,ans,index,digits);
        return ans;
    }
};