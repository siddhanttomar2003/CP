class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        vector<int>zero,one;
        int n=groups.size();
        int curr1=0;// track start with 0 subsequence
        int curr2=1;// track start with 1 subsequence
        for(int i=0;i<n;i++){
          if(groups[i]==curr1){
            zero.push_back(i);
            curr1^=1;
          }
           if(groups[i]==curr2){
            one.push_back(i);
            curr2^=1;
          }
        }
        if(zero.size()<one.size()){
            swap(zero,one);
        }
        for(auto it:zero)ans.push_back(words[it]);
        return ans;
    }
};