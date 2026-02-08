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
    int cal(bool &ans, TreeNode *root){
        if(root == NULL)return 0;
        int left = cal(ans, root -> left);
        int right = cal(ans, root -> right);
        if(abs(right - left) > 1)ans = false;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        cal(ans, root);
        return ans;
    }
};