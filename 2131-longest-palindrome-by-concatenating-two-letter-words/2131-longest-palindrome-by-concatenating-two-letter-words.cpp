class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        int count=0;
        for(auto it:words){
            mp[it]++;
        }
        bool ex=0;
        for(auto it:mp){
            int can=it.second;
            string req=it.first;
            reverse(req.begin(),req.end());
            if(req==it.first){
                if(can&1 && !ex){
                    count+=2;
                    ex=1;
                    can--;
                }
                else if(can&1)can--;
                count+=(2*can);
            } 
            else if(mp.find(req)!=mp.end() && mp[req]>0){
                 int mini=min(mp[req],mp[it.first]);
                 mp[req]-=mini;
                 mp[it.first]-=mini;
                 count+=(4*mini);
            }
        }

        return count;
        
    }
};