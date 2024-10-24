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
    bool isLeaf(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    bool cal(TreeNode* root1, TreeNode* root2) {
         if (root1 == NULL || root2 == NULL) {
        return root1 == root2;
    }
        if (isLeaf(root1) && isLeaf(root2)) {
        return root1->val == root2->val;
    }
        bool cal1 = (root1->left, root2->left);
        bool cal2 = (root1->left, root2->right);
        bool cal3 = (root1->right, root2->left);
        bool cal4 = (root1->right, root2->right);
        if ((cal1 && cal4)  || (cal2 && cal4) && (root1->val == root2->val))
            return true;
        return false;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
            return false;
        if (!root1 && !root2)
            return true;
        if (root1->val != root2->val)
            return false;
        return cal(root1, root2);
    }
};