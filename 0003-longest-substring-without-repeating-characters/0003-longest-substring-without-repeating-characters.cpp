class Solution {
public:
  bool check(vector<int> &temp){
    for(int i=0;i<256;i++){
        if(temp[i]>1)return false;
    }
    return true;
  }
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int ans=0;
        
        vector<int>temp(256,0);
        while(j<s.length()){
            temp[s[j]]++;
            if(check(temp)){
                ans=max(ans,j-i+1);
                j++;
            }
            else {
                while(i<=j && !check(temp)){
                    temp[s[i]]--;i++;
                }
                ans=max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};