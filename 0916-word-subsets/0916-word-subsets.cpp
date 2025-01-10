// class TrieNode {
//     public :
//     vector<TreeNode*>child;
//     bool count_till;
//     TrieNode(){
//         child.resize(26,NULL);
//         count_till=0;
//     }
// };
// class Trie {
//      TrieNode *root;
//      Trie (){
//         root=new TrieNode();
//      }
//      void insert(string &s){
//         TrieNode *curr=root;
//         for(int i=0;i<s.size();i++){
//             if(curr->child[s[i]-97]==NULL){
//                 curr->child[s[i]-97]=new TrieNode();
//             }
//             curr=curr->child[s[i]-97];
//         }
//         curr->count_till++;
//      }
//      int count(string &s){
//         int ans=0;
//         for(int i=0;i<s.size();i++){
//             if(curr->child[s[i]-97]!=NULL){
//                 curr=curr->child[s[i]-97];
//                 ans+=curr->count_till;
//             }
//         }
//         return ans;
//      }

// };
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int tar=words2.size();
        int n=words1.size();
        vector<string>ans;
        vector<int>hash(26,0);
        for(int i=0;i<tar;i++){
            vector<int>temp(26,0);
            for(int j=0;j<words2[i].size();j++){
                temp[words2[i][j]-97]++;
            }
            for(int j=0;j<26;j++){
                hash[j]=max(hash[j],temp[j]);
            }
        }
        for(int i=0;i<n;i++){
            string t=words1[i];
            vector<int>curr(26,0);
            for(int j=0;j<t.size();j++){
                curr[t[j]-97]++;
            }
            bool check=true;
            for(int j=0;j<26;j++){
                if(curr[j]<hash[j])check=false;
            }
            if(check)ans.push_back(t);
        }
        return ans;

    }
};