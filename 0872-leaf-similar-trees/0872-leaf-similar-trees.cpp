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
    // time/space: O(n)/O(n)
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // get leaf value sequences
        string leaf1 = "", leaf2 = "";
        getLeaf(root1, leaf1);
        getLeaf(root2, leaf2);
        
        // check sequences
        return leaf1 == leaf2;
    }
private:
    void getLeaf(TreeNode* root, string& leaf) {
        // terminate
        if (root == NULL) return;

        // inorder traversal
        getLeaf(root->left, leaf);
        if ((root->left == NULL) && (root->right == NULL)) {
            leaf += (to_string(root->val) + ",");
        }
        getLeaf(root->right, leaf);
    }
};