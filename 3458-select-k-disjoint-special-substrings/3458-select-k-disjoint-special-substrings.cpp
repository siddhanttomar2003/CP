typedef pair<int,int> pi;
class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        if(k==0)return true;
        vector<int> start(26, -1), end(26, -1);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (start[s[i] - 97] == -1)
                start[s[i] - 97] = i;
            end[s[i] - 97] = i;
        }
        int cal = 0;
        vector<pi>intervals;
        for (int i = 0; i < 26; i++){
            if(start[i]!=-1){
                int o=start[i];
                int e=end[i];
                for(int j=start[i]+1;j<end[i];j++){
                    e=max(e,end[s[j]-97]);
                    if(start[s[j]-97]!=-1)o=min(o,start[s[j]-97]);
                }
                intervals.push_back({o,e});
            }
        }
        sort(intervals.begin(),intervals.end(),[](pi a, pi b){
         return a.second<b.second;
        });
        int st=intervals[0].first;
        int en=intervals[0].second;
        if(st==0 && en==n-1)return false;
        cal=1;
        for(int i=1;i<intervals.size();i++){
            int curr_s=intervals[i].first;
            int curr_e=intervals[i].second;
            if(curr_s>en && curr_e-curr_s+1!=n){
             cal++;
             en=curr_e;
             st=curr_s;
            }
        } 
        return cal>=k;
    }
};