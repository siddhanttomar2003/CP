class Solution {
public:
    int maxFreeTime(int t, vector<int>& s, vector<int>& e) {
         int n=s.size();
         map<int,int>mp;
         mp[s[0]]++;
         mp[t-e[n-1]]++;
         for(int i=0;i<n-1;i++){
             mp[s[i+1]-e[i]]++;
         }
        // for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
        int curr_left=0;
        vector<int>l(n,0),r(n,0);
        for(int i=0;i<n;i++){
              l[i]=s[i]-curr_left;
             curr_left=e[i];
            // cout<<l[i]<<" ";
        }
        // cout<<endl;
        int curr_right=t;
        for(int i=n-1;i>=0;i--){
            r[i]=curr_right-e[i];
            curr_right=s[i];
            // cout<<r[i]<<" ";
        }
        // cout<<endl;
        
        int ans=0;
        for(int i=0;i<n;i++){
            int size=e[i]-s[i];
            cout<<l[i]<<" "<<r[i]<<endl;
            ans=max(ans,l[i]+r[i]);
            mp[l[i]]--;
            if(mp[l[i]]==0)mp.erase(l[i]);
            mp[r[i]]--;
            if(mp[r[i]]==0)mp.erase(r[i]);
            auto it=mp.lower_bound(size);
            if(it!=mp.end()){
                ans=max(ans,l[i]+r[i]+size);
            }
            mp[l[i]]++;
            mp[r[i]]++;
        }
        return ans;
    }
};