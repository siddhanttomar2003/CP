class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        int bitmask=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<word.length();i++){
         bitmask=bitmask^(1<<(word[i]-'a'));
         ans+=mp[bitmask];// when all are coming even number of times
         // when one char is coming odd no. of times
         for(int j=0;j<10;j++){
            int num=bitmask;
            num^=(1<<j);
            ans+=mp[num];
         }
         mp[bitmask]++;
        }
        return ans;
    }
};