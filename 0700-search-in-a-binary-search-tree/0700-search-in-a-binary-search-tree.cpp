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
    TreeNode* recur(TreeNode *root, int val) {
        if (root == nullptr || root->val == val) {
            return root;
        }
        if (root->val < val) {
            return recur(root->right, val);
        }
        return recur(root->left, val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return recur(root, val);
    }
};
