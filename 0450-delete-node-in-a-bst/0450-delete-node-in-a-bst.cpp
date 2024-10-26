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
    void child_parent(map<TreeNode *,TreeNode *>&mp, TreeNode * root ){
      queue<TreeNode *>q;
      q.push(root);
      while(q.size()>0){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode *curr=q.front();
            q.pop();
            if(curr->left!=NULL){
                mp[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                mp[curr->right]=curr;
                q.push(curr->right);
            }
        }
      }
    }
    void find_key(TreeNode *root, int key, TreeNode * &tar){
        if(!root)return;
        if(root->val==key){
            tar=root;
        }
        find_key(root->left,key,tar);
        find_key(root->right,key,tar);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        map<TreeNode *, TreeNode *>mp;

        if(root==NULL)return NULL;
        child_parent(mp,root);
        TreeNode *tar=NULL;
        find_key(root,key,tar);
        if(tar==NULL)return root;
        TreeNode *replacement=NULL;
        if(tar->right==NULL){
            return tar->left;
        }
        TreeNode *temp=tar->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        if(mp[temp]!=tar){
            TreeNode* par=mp[temp];
            par->left=NULL;
        }
        else {
            tar->right=NULL;
        }
        TreeNode *l=tar->left;
        TreeNode *r=tar->right;
        if(mp.find(tar)==mp.end()){// means it is the root;
           temp->left=l;
           temp->right=r;
        //    return temp;
         root=temp;
        }
        else {
            TreeNode* par=mp[tar];
            if(par->left==tar){
                par->left=temp;
            }
            else {
                par->right=temp;
            }
            temp->left=l;
           temp->right=r;
        }
        cout<<temp->val<<" "<<tar->val<<"";
        return root;

    }
};