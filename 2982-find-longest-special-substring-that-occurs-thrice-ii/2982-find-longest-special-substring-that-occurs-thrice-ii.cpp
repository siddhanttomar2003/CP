class Solution {
public:
    int maximumLength(string s) {
        map<char,map<int,int>>mp;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            int curr = 1;
            while (i < s.size() && s[i] == s[i + 1]) {
                mp[c][curr]++;
                i++;
                curr++;
            }
            mp[c][curr]++;
        }
    //   for(auto it:mp){
    //     cout<<it.first<<"->";
    //     for(auto it2:it.second){
    //         cout<<it2.first<<" "<<it2.second<<endl;
    //     }
    //     cout<<endl;
    //   }
    int maxi=-1;
    for(auto it:mp){
        vector<pair<int,int>>temp;
        for(auto it2:it.second){
            temp.push_back({it2.first,it2.second});
        }
        int t_n=temp.size();
        for(int i=0;i<t_n;i++){
            int req=3-temp[i].second;
            if(req<=0){
                maxi=max(maxi,temp[i].first);
            }
            else {
                if(req==1 && i+1<t_n){
                    maxi=max(maxi,temp[i].first);
                }
                if(req==2 && i+2<t_n){
                    maxi=max(maxi,temp[i].first);
                }
            }

        }
    }
       return maxi;
    }
};