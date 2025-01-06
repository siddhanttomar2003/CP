class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>pre_cum(n,0),suff_cum(n,0);
        int curr_s=0,curr_e=0;
        for(int i=0;i<n;i++){
            if(i>=1){
                pre_cum[i]=(pre_cum[i-1]+curr_s);
            }
            else pre_cum[i]=curr_s;
            if(n-i-1<n-1){
                suff_cum[n-i-1]=(suff_cum[n-i]+curr_e);
            }
            else suff_cum[n-i-1]=curr_e;
            if(boxes[i]=='1')curr_s++;
            if(boxes[n-i-1]=='1')curr_e++;
        }
        vector<int>ans(n,0);
        for(int i=0;i<boxes.size();i++){
              ans[i]=pre_cum[i]+suff_cum[i];
        }
        return ans;
    }
};