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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        q.push(nullptr);
        vector<int>level;
       while(q.size()>1){     
            if(!q.front()){
                q.push(nullptr);
                q.pop();
                level.clear();
                continue;
            }
            TreeNode * temp=q.front();
            level.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right)q.push(temp->right);
            q.pop();
        }   
        return level[0];

   }
};