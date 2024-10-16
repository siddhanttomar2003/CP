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
    vector<vector<int>> levelOrder(TreeNode* root) {
       
        vector<vector<int>>ans;
        if(root==NULL)return ans;
         queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            int curr_size=q.size();
            vector<int>temp;
            for(int i=0;i<curr_size;i++){
                TreeNode* curr= q.front(); temp.push_back(curr->val);
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};