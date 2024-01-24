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

    void recur(TreeNode* root, vector<int> v, int& a) {
        if (root == NULL)
            return;
        v[root->val]++;
        if (root->left == NULL && root->right == NULL) {
            int odd=0; int count_same=0;
            for(int i=1;i<=9;i++){
                if(v[i]&1)odd++;

            }
            if(odd==1||odd==0){a++;}return;

        }
        recur(root->left, v, a);
        recur(root->right, v, a);
        v[root->val]--;
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        int a = 0;
        vector<int> v(10,0);
        recur(root, v, a);
        return a;
    }
};