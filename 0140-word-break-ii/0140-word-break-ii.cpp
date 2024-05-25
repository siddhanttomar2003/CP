class Solution {
public:
    void recur(vector<string> &ans, string &temp, unordered_map<string,int> &st, string s, int i){
        if(i==s.length()){
            ans.push_back(temp);
            return;
        }
        string custom =temp;
        string curr="";
        for(int j=i;j<s.length();j++){
            curr+=s[j];
            if(st[curr]>0){
                temp+=curr;
                if(j!=s.length()-1)
                temp+=" ";
                recur(ans,temp,st,s,j+1);
                temp=custom;
                
            }
        }
      
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         unordered_map<string,int>st;
        for(int i=0;i<wordDict.size();i++){
            st[wordDict[i]]++;
        }
        string temp="";
        vector<string>ans;
        recur(ans,temp,st,s,0);
        return ans;
    }
};