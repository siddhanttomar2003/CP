class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ans;
        int n=words.size();
        vector<int>pre(n+1,0);
        for(int i=1;i<=n;i++){
            string temp=words[i-1];
            char s=temp[0];
            char e=temp[temp.size()-1];
            if((s=='a' || s=='e' || s=='i' || s=='o' || s=='u') && (e=='a' || e=='e' || e=='i' || e=='o' || e=='u')){
                pre[i]=1+pre[i-1];
            }
            else pre[i]=pre[i-1];
        }
        for(int i=0;i<queries.size();i++){
            int s=queries[i][0];
            int e=queries[i][1];
            ans.push_back(pre[e+1]-pre[s]);
        }
        return ans;
    }
};