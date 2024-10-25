/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* construct(vector<int>& preorder, int s_pre, int e_pre,
                        vector<int>& inorder, int s_in, int e_in,
                        map<int, int>& mp) {
                        if(e_in<s_in || e_pre<s_pre)return NULL;
        TreeNode* root = new TreeNode(preorder[s_pre]);
        int ind = mp[preorder[s_pre]];
        int left_count = ind - s_in;
        root->left = construct(preorder, s_pre + 1, s_pre + left_count, inorder,
                               s_in ,ind-1, mp);
        root->right=construct(preorder,s_pre+left_count+1,e_pre,inorder,ind+1,e_in,mp);          
        return root;             
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        int n = preorder.size();
        if(preorder[0]==-1){
            TreeNode * temp=new TreeNode (-1);
            return temp;
        }
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return construct(preorder, 0, n - 1, inorder, 0, n - 1, mp);
    }
};