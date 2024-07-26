#include<iostream>
using namespace std;
class TrieNode {
    public:
        TrieNode *words[26];
        bool isSet;
        TrieNode(){
            for(int i=0;i<26;i++){
                words[i]=NULL;
            }
            isSet=true;
        }

};
class Trie{
 TrieNode * root;
 Trie(){
    root=new TrieNode();
 }
 void insert(string word){
  TrieNode *curr=root;
   for(int i=0;i<word.size();i++){
    int index=word[i]-'a';
    if(curr->words[index]==nullptr){
        curr->words[index]=new TrieNode();
    }
    curr=curr->words[index];
   }
   curr->isSet=true;
 }
   bool search(string word){
    TrieNode *curr=root;
    for(int i=0;i<word.size();i++){
        int index=word[i]-'a';
        if(curr->word[index]==nullptr)return false;
        curr=curr->word[index]
    }
    return curr->isSet;
   }
   bool isPrefixexist(string word){
    TrieNode * curr=root;
    for(int i=0;i<word.size();i++){
        int index=word[i]-'a';
        if(curr->word[index]==NULL)return false;
        curr=curr->word[index];
    }
    return true;
   }
};

int main()
{

return 0;
}