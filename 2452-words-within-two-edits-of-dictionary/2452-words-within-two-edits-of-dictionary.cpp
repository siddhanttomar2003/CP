class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(auto it : queries){
            string curr = it;
            int size = curr.size();
            for(auto it2 : dictionary){
                int diff = 0;
                for(int i = 0; i < size; i++){
                    if(curr[i] != it2[i])diff++;
                }
                if(diff <= 2){
                    ans.push_back(curr);
                    break;
                }
            }
        }
        return ans;
    }
};