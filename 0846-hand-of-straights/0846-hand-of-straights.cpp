class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int s) {
        int n=hand.size();
        if(n%s!=0)return false;
        int times=n/s;
        map<int,int>mp;
        for(auto it:hand)mp[it]++;
        while(times--){
            int start=mp.begin()->first;
            mp[start]--;
            if(mp[start]==0)mp.erase(start);
            for(int i=1;i<s;i++){
                if(mp.find(start+i)!=mp.end()){
                     mp[start+i]--;
                     if(mp[start+i]==0)mp.erase(start+i);
                }
                else return false;
            }
        }
        return true;
    }
};
