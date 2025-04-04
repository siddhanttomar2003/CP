/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        map<TreeNode *, TreeNode *>child_par;
        queue<TreeNode *>q;
        q.push(root);
        vector<TreeNode *>leaves;
        while(q.size()>0){
            int size=q.size();
            vector<TreeNode *>temp;
            for(int i=0;i<size;i++){
                TreeNode * par=q.front();
                q.pop();
                temp.push_back(par);
                if(par->left!=NULL){
                    temp.push_back(par->left);
                    child_par[par->left]=par;
                    q.push(par->left);
                }
                if(par->right!=NULL){
                    temp.push_back(par->right);
                    child_par[par->right]=par;
                    q.push(par->right);
                }
            }
            leaves=temp;
            
        }
        // for(int i=0;i<leaves.size();i++)cout<<leaves[i]<<" "<<endl;
        // return root;
        if(leaves.size()==1)return leaves[0];
        if(leaves.size()==0)return root;
        map<TreeNode *,int>mp;
        int req=leaves.size();
        for(int i=0;i<leaves.size();i++){
             TreeNode *temp=leaves[i];
             while(child_par[temp]!=root){
                mp[temp]++;
                if(mp[temp]==req)return temp;
                temp=child_par[temp];
             }
             mp[temp]++;
             if(mp[temp]==req)return temp;
        }
        return root;
    }
};