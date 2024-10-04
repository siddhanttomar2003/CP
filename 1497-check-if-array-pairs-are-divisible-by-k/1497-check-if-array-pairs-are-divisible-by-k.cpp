class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            arr[i]=(arr[i]%k+k)%k;
            mp[arr[i]]++;
        }
        if(mp.find(0)!=mp.end()){
            long long t=mp[0];
            mp.erase(0);
            if(t&1)return false;
        }
        // for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
        for(auto it:mp){
            int curr=it.first;
            int req=k-it.first;
            if(mp[curr]==mp[req])continue;
             return false;
        }
        return true;

    }
};