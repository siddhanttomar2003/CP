class TrieNode {
   public:
    vector<TrieNode *> child;
    int till_this;
    TrieNode(){
        child.resize(26,0);
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        till_this=0;
    }
};
class Trie {
    public:
     TrieNode *root;
     Trie(){
        root=new TrieNode();
     }
     void insert(string &s){
        TrieNode * curr=root;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(curr->child[c-97]==NULL){
                curr->child[c-97]=new TrieNode();
            }
            curr=curr->child[c-97];
            curr->till_this++;
        }
     }
     int find_pre(string &s){
         bool check=true;
         TrieNode *curr=root;
         for(int i=0;i<s.size();i++){
            char c=s[i];
            if(curr->child[c-97]!=NULL){
               curr= curr->child[c-97];
            }
            else {
                check=false;break;
            }
         }
         if(check)return curr->till_this;
         return 0;
     }

};
class Solution {
public:

    int prefixCount(vector<string>& words, string pref) {
        Trie t;
        for(int i=0;i<words.size();i++){
               t.insert(words[i]);
        }
        return t.find_pre(pref);
    }
};