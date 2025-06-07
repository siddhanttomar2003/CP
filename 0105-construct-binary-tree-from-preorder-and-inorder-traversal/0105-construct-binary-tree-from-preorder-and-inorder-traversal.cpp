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
    TreeNode * build(vector<int>&pre,vector<int>&ino, int pre_s,int in_s, int pre_e, int in_e, map<int,int>&pos){
        if(pre_s>pre_e || in_s>in_e)return NULL;
        int posi=pos[pre[pre_s]];
        TreeNode * node= new TreeNode(pre[pre_s]);
        int l=pos[pre[pre_s]]-in_s;
        int r= in_e - pos[pre[pre_s]];
        node->left=build(pre,ino,pre_s+1,in_s,pre_s+l,posi-1,pos);
        node->right=build(pre,ino,pre_s+l+1,posi+1,pre_s+l+r,in_e,pos);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>pos;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            pos[inorder[i]]=i;
        }
        return build(preorder,inorder,0,0,n-1,n-1,pos);
    }
};
