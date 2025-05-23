class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>f(26,-1),l(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++){
           if(f[s[i]-97]==-1)f[s[i]-97]=i;
           l[s[i]-97]=i;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
           int curr=1;
           int last=l[s[i]-97];
           while(i<last && i<n){
               last=max(last,l[s[i]-97]);
               i++;
               curr++;
           }
           ans.push_back(curr);
        }
        return ans;
    }
};