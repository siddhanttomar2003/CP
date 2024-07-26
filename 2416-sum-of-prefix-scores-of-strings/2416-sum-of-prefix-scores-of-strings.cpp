class TrieNode {
public:
    TrieNode *child[26];
    int prefixScore;  // Stores the score of all prefixes ending at this node
    bool isExist;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        isExist = false;
        prefixScore = 0;
    }
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (curr->child[index] == NULL) {
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
            curr->prefixScore++;
        }
        curr->isExist = true;
    }

    int getPrefixScore(string prefix) {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (curr->child[index] == NULL) return 0;
            curr = curr->child[index];
        }
        return curr->prefixScore;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie trie;
        for (int i = 0; i < words.size(); i++) {
            trie.insert(words[i]);
        }
        for (int i = 0; i < words.size(); i++) {
            int curr = 0;
            for (int j = 1; j <= words[i].size(); j++) {
                curr += trie.getPrefixScore(words[i].substr(0, j));
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
