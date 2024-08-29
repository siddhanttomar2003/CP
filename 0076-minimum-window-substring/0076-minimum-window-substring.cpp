class Solution {
public:
    bool check(map<char,int>&mp1, map<char,int>&mp2){
        for(auto it:mp1){
            if(mp2.find(it.first)!=mp2.end()){
                if(mp2[it.first]>=mp1[it.first])continue;
                else return false;
            }
            else return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(t.size()>s.size())return "";
        map<char,int>mp1;
        map<char,int>mp2;
        int j; int i=0;
        for( j=0;j<t.size();j++){
         mp1[t[j]]++;
         mp2[s[j]]++;
        }
        string ans="";
        int len=INT_MAX;
        int pos_start= -1;
        int pos_end= -1;
        int n=s.size();
        j--;
        if(check(mp1,mp2)){
            len=t.size();
            pos_start=0;
            pos_end=len-1;
        }
        while(j+1<n){
          j++;
          mp2[s[j]]++;
          while(check(mp1,mp2) && j>=i){
            if(j-i+1<len){
                pos_start=i;
                pos_end=j;
                len=j-i+1;
            }
            mp2[s[i]]--;
            if(mp2[s[i]]==0)mp2.erase(s[i]);
            i++;
          }
        }
        
        if(pos_start==-1)return "";
        for(int i=pos_start;i<=pos_end;i++){ans+=s[i];}
        return ans;
    }
};