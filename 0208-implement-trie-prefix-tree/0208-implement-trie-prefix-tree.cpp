class TrieNode {
     public:
     TrieNode *child[26];
     bool isExist;
     TrieNode (){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        isExist=false;
     }
};
class Trie {
public:
      TrieNode *root;
    Trie() {
        root=new TrieNode();
    }

    
    void insert(string word) {
        TrieNode *curr=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->child[index]==NULL){
                curr->child[index]=new TrieNode();
            }
            curr=curr->child[index];
        }
        curr->isExist=true;
    }
    
    bool search(string word) {
        TrieNode *curr=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->child[index]==NULL)return false;
            curr=curr->child[index];
        }
        return curr->isExist;
    }
    
    bool startsWith(string word) {
          TrieNode *curr=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->child[index]==NULL)return false;
            curr=curr->child[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */