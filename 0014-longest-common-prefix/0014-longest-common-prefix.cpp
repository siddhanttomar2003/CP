class TrieNode {
public:
    vector<TrieNode*> child;
    int count;
    TrieNode() {
        child.resize(26, NULL);
        count = 0;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int maxi = 0;
        TrieNode * root = new TrieNode();
        string ans = "";
        for(auto it : strs){
            TrieNode * curr = root;
            string temp = "";
            for(auto ch : it){
                temp += ch;
                int c = ch - 97;
                if(curr -> child[c] == NULL){
                    curr -> child[c] = new TrieNode();
                }
                curr = curr -> child[c];
                curr -> count ++ ;
                if(curr -> count == n)ans = temp;
            }
        }
        return ans;
    }
};