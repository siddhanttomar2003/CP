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
   string checksize(){
    TrieNode *curr=root;
    bool flag=true;
    // int ans=0;
    string temp="";
    TrieNode *tempo=root;
    while(flag){
        int tempc=0;
        
        for(int i=0;i<26;i++){
              if(curr->child[i]!=NULL){
                tempc++;
                temp+=(char)(97+i);
                tempo=curr->child[i];
              }
              if(tempc>=2){
                temp.pop_back();temp.pop_back();
                flag=false;break;
              }
        }

        curr=tempo;
        if(curr->isExist==true){
            flag=false;break;
        }
        // ans++;
    }
    return temp;
   }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // if(strs.size()==0)return "";
        Trie t;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()==0)return "";
            t.insert(strs[i]);
        }
       string fans= t.checksize();
      return fans;
    }
};