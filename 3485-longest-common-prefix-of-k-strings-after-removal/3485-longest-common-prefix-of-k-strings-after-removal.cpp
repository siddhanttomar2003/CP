class TrieNode {
   public:
   vector<TrieNode *>node;
   int count;
   bool counted;
   TrieNode(){
    node.resize(26,NULL);
    count=0;
    counted=false;
   }
};
class Trie {
    public:
    TrieNode *root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string s, map<int,int>&mp, int k){
        int size=s.size();
        TrieNode *curr=root;
        for(int i=0;i<size;i++){
            char c=s[i];
            if(curr->node[c-97]==NULL){
                curr->node[c-97]=new TrieNode();
            }
            curr=curr->node[c-97];
            curr->count++;
            if(curr->count>=k && !(curr->counted)){
                curr->counted=true;
                mp[i+1]++;
            }
        }
    }
    void remove(string s, map<int,int>&mp, int k){
        int size=s.size();
        TrieNode *curr=root;
        for(int i=0;i<size;i++){
            char c=s[i];
            curr=curr->node[c-97];
            curr->count--;
            if(curr->count<k && curr->counted){
                  curr->counted=false;
                  mp[i+1]--;
                  if(mp[i+1]==0)mp.erase(i+1);
            }
        }
    }
};
class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        int n=words.size();
        Trie t;
        map<int,int>mp;
        for(int i=0;i<n;i++){
           t.insert(words[i],mp,k);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
         t.remove(words[i],mp,k);
         if(mp.size()>0){
            auto it=prev(mp.end());
            ans[i]=it->first;
         }
         
         else ans[i]=0;
         t.insert(words[i],mp,k);
        }
        return ans;
    }
};