class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        for(auto it:tasks)mp[it-65]++;
        vector<int>freq(26,0);
        for(int i=0;i<26;i++)freq[i]=mp[i];
        sort(freq.rbegin(),freq.rend());
        int spots=freq[0]-1;
        int free=spots*n;
        for(int i=1;i<26;i++){
             if(min(freq[i],spots)<=free)free-=min(freq[i],spots);
        }
        return tasks.size()+max(0,free);
    }
};