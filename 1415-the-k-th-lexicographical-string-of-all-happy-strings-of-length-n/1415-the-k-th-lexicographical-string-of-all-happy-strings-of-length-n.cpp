class Solution {
public:
    void build(vector<string> &ans, string curr, int n, int i, char last){
        if(i == n){
            ans.push_back(curr);
            return;
        }
        if(last != 'a'){
            build(ans, curr + 'a', n, i + 1, 'a');
        }
        if(last != 'b'){
            build(ans, curr + 'b', n, i + 1, 'b');
        }
        if(last != 'c'){
            build(ans, curr + 'c', n, i + 1, 'c');
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        string curr = "";
        char last = 'd';
        build(ans, curr, n, 0, last);
        sort(ans.begin(), ans.end());
        if(k > ans.size())return "";
        return ans[k - 1];
    }
};