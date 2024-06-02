class Solution {
public:
    int find_ways(int i, int jump, int back ,map<vector<int>, int> &mp,int k){
        if(i>k+1)return 0;// not possible as we can back atmost 1 times continuously
        if(mp.find({i,jump,back})!=mp.end())return mp[{i,jump,back}];
        int ans=(i==k);
        if(back&&i>0){
            ans+=(find_ways(i-1,jump,0,mp,k));
        }
        ans+=(find_ways(i+pow(2,jump),jump+1,1,mp,k));
        return mp[{i,jump,back}]=ans;

    }
    int waysToReachStair(int k) {
       map<vector<int>,int>mp;
        int i=1;
        int jump=0;
        int back=1;
        return find_ways(i,jump,back,mp,k);
    }
};