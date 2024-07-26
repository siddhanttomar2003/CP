class TrieNode {
    public:
        TrieNode *child[26];
        bool isExist;
        TrieNode (){
            // child=new TrieNode();
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
            isExist=false;
        }
};
class Trie{
    public:
   TrieNode *root;
   Trie(){
    root=new TrieNode();
   }
   void insert(string word){
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
   bool search(string word){
    //    string tempo="";
       TrieNode *curr=root;
       for(int i=0;i<word.size();i++){
           int index=word[i]-'a';
           if(curr->child[index]->isExist){
            // tempo+=(char)(97+i);
            curr=curr->child[index];
           }
           else return false;   
       }
     return true;
   }
};
class Solution {
public:
   
    string longestWord(vector<string>& words) {
        Trie t;
        for(int i=0;i<words.size();i++){
            t.insert(words[i]);
        }
        string ans="";
        for(int i=0;i<words.size();i++){
         if(t.search(words[i])){
            if(words[i].size()>=ans.size()){
                if(words[i].size()==ans.size() && words[i]<ans)ans=words[i];
                if(words[i].size()>ans.size())ans=words[i];
         }
        }
        }
        return ans;

    }
};