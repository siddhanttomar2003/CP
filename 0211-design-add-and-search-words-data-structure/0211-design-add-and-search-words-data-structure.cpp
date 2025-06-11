class Trie {
public:
    vector<Trie*> node;
    bool is_exist;
    Trie() {
        node.resize(26, NULL);
        is_exist = false;
    }
};
class WordDictionary {
public:
    Trie* root;
    WordDictionary() { root = new Trie(); }

    void addWord(string word) {
        Trie* temp = root;
        for (int i = 0; i < word.size(); i++) {
            int c = word[i]-97;
            if (temp->node[c] == NULL) {
                temp->node[c] = new Trie();
            }
            temp = temp->node[c];
        }
        temp->is_exist = true;
    }
    bool cal(string& word, int i, Trie* temp) {
        if (i == word.size()) {
            return temp->is_exist;
        }
        bool check = false;
        if (word[i] != '.') {
            int c = word[i] - 97;
            if (temp->node[c] == NULL)
                return false;
            check |= cal(word, i + 1, temp->node[c]);
        } else {
            for (int j = 0; j < 26; j++) {
                if (temp->node[j] != NULL) {
                    check |= cal(word, i + 1, temp->node[j]);
                }
            }
        }
        return check;
    }
    bool search(string word) {
        Trie* temp = root;
        return cal(word, 0, temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */