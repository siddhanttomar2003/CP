class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>>v(numRows);
        int curr=0;
        while(curr<s.size())
        {
            bool check=false;
            for(int i=0;i<numRows;i++){
                v[i].push_back(s[curr]);
                curr++;
                if(curr==s.size()){
                    check=true;break;
                }
            }
            if(check)break;
            int j=numRows-2;
            for(int i=0;i<numRows-2;i++){
                 v[j].push_back(s[curr]);
                 curr++;
                 j--;
                 if(curr==s.size()){
                    break;
                }
            }
            
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<v[i].size();j++){
                ans+=v[i][j];
            }
        }
        return ans;

    }
};