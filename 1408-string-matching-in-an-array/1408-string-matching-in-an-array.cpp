class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            string curr=words[i];
            for(int j=0;j<curr.size();j++){
                string temp="";
                for(int k=j;k<curr.size();k++){
                        temp+=curr[k];
                        mp[temp]++;
                }
            }
        }
        vector<string>ans;
        for(int i=0;i<words.size();i++){
             if(mp[words[i]]>1){
                ans.push_back(words[i]);
             }
        }
        return ans;
    }
};