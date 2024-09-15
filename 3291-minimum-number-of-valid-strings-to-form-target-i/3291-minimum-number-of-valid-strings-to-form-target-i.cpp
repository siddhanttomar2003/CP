class Solution {
public:
    class TrieNode {
    public:
        TrieNode* child[26];
        bool isExist;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            isExist = false;
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() { root = new TrieNode(); }

        void insert(string word) {
            TrieNode* curr = root;
            for (int i = 0; i < word.size(); i++) {
                int index = word[i] - 'a';
                if (curr->child[index] == NULL) {
                    curr->child[index] = new TrieNode();
                }
                curr = curr->child[index];
            }
            curr->isExist = true;
        }

        bool startsWith(string word) {
            TrieNode* curr = root;
            for (int i = 0; i < word.size(); i++) {
                int index = word[i] - 'a';
                if (curr->child[index] == NULL)
                    return false;
                curr = curr->child[index];
            }
            return true;
        }
    };

    long long cal(string target, int i, Trie& t, vector<long long>& dp) {
        if (i == target.size()) {
            return 0;
        }
        if (dp[i] != INT_MAX)
            return dp[i];
        TrieNode *temp=t.root;
        long long ways = INT_MAX;
        for (int j = i; j < target.size(); j++) {
            char curr=target[j];
            if(temp->child[curr-'a']!=NULL){
               temp=temp->child[curr-'a'];
               ways=min(ways,1+cal(target,j+1,t,dp));
            }
            else break;
        }
        return dp[i] = ways;
    }

    int minValidStrings(vector<string>& words, string target) {
        Trie t;
        for (int i = 0; i < words.size(); i++) {
            t.insert(words[i]);
        }
        int n = target.size();
        vector<long long> dp(n, INT_MAX);
        long long ans = cal(target, 0, t, dp);
        return ans == INT_MAX ? -1 : ans;  
    }
};