class TrieNode {
    public:
    TrieNode* child[26];
     int times;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        times=0;
    }
};
class Trie {
 public:
 TrieNode *root;
 Trie(){
    root=new TrieNode();
 }
 void insert(string s){
    TrieNode * curr=root;
    for(int i=0;i<s.size();i++){
        int ind=s[i]-97;
        if(curr->child[ind]==NULL){
            curr->child[ind]=new TrieNode ();
        }
        curr=curr->child[ind];
        curr->times++;
    }
 }
    int cal(string t){
        int ans=0;
        TrieNode *curr=root;
        for(int i=0;i<t.size();i++){
            int ind=t[i]-97;
            if(curr->child[ind]!=NULL){
                curr=curr->child[ind];
                ans+=curr->times;
            }
            else break;
        }
        return ans;
    }
 
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        for(int i=0;i<words.size();i++){
            t.insert(words[i]);
        }
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            int curr=0;
            curr=t.cal(words[i]);
            ans.push_back(curr);
        }
        return ans;
    }
};