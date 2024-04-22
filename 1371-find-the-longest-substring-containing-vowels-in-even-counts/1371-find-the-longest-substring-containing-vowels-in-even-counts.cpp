class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int currbit=0;
        int ans=0;
        mp[0]=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                currbit^=1<<(int)(s[i]-'a');
            }
            if(mp.find(currbit)==mp.end())mp[currbit]=i;
            ans=max(ans,i-mp[currbit]);
        }
        return ans;
    }
};