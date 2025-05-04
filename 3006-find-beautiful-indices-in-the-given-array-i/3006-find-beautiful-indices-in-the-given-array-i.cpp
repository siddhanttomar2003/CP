class Solution {
public:
    void buildlps(vector<int>&lps, string &p){
        int len=0;
        int i=1;
        lps[0]=0;
        while(i<p.size()){
            if(p[i]==p[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else {
                if(len!=0){
                    len=lps[len-1];
                }
                else {
                    lps[i]=0;i++;
                }
            }
        }
    }
    vector<int> construct(vector<int> &lps, string &s, string &p){
        vector<int>ans;
        int i=0,j=0;
        while(i<s.size()){
            if(p[j]==s[i]){
                i++;j++;
                if(j==p.size()){
                    ans.push_back(i-j);
                    j=lps[j-1];
                }
            }
            else {
                if(j!=0){
                    j=lps[j-1];
                }
                else {
                    i++;
                }
            }
        }
        return ans;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n1=a.size(),n2=b.size();
        vector<int>lps1(n1),lps2(n2);
        buildlps(lps1,a);
        buildlps(lps2,b);
        vector<int>f=construct(lps1,s,a);
        vector<int>t=construct(lps2,s,b);
        vector<int>ans;
        for(int i=0;i<f.size();i++){
            int ind1=lower_bound(t.begin(),t.end(),f[i]-k)-t.begin();
            if(ind1!=t.size() && t[ind1]<=f[i]+k)ans.push_back(f[i]);
        }
        return ans;
    }
};