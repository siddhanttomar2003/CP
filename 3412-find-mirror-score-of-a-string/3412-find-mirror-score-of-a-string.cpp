class Solution {
public:
    long long calculateScore(string s) {
        long long ans=0;
        map<char,vector<long long>>mp;
        for(long long i=0;i<s.size();i++){
             mp[s[i]].push_back(i);
             int ex_up=s[i]-97;
             int down=122-ex_up;
             char mirr=(char)(down);
             if(mp.find(mirr)!=mp.end()){
               long long ind=mp[mirr].back();
               ans+=(i-ind);
               mp[mirr].pop_back();
               if(mp[mirr].size()==0)mp.erase(mirr);
               mp[s[i]].pop_back();
               if(mp[s[i]].size()==0)mp.erase(s[i]);
             }
        }
        
        return ans;

    }
};