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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while (st.size() > 0) {
            TreeNode* curr = st.top();
            if (curr != NULL) {
                st.push(curr->left);
            } else {
                st.pop();
                if (st.size() > 0) {
                    curr = st.top();st.pop();
                    ans.push_back(curr->val);
                    st.push(curr->right);
                }
            }
        }
        return ans;
    }
};