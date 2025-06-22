class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int times = (int)ceil((n*1.0)/(k*1.0));
        int i = 0, j = 0;
        vector<string>ans;
        while(j < times){
            string temp = "";
            for(int l = 0; l < k; l++){
                if(i < n){
                    temp += s[i];
                    i++;
                }
                else temp += fill;
            }
            ans.push_back(temp);
            j++;
        }
        return ans;
    }
};