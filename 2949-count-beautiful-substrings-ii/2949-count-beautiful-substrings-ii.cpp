class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')s[i]='1';
            else s[i]='0';
        }

        unordered_map<int,vector<int>> mp;
        mp[0].push_back(0);

        int sum=0;
        int count=0;
        int size=0;
        for(int i=1;i<=k;i++){
            if(i*i%k==0){
                size=i; break;
            }
        }
        size*=2;
        for(int i=1;i<s.size()+1;i++){
            if(s[i-1]=='1') sum++;
            else sum--;

            for(auto itr:mp[sum]) count+=((i-itr)%(size)==0);
            mp[sum].push_back(i);
        }
        return count;
    }
};