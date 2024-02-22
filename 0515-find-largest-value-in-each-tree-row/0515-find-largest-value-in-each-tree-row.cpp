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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr)return ans;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int largest=INT_MIN;
            for(int i=0;i<size;i++){
              TreeNode *temp=q.front();q.pop();
              if(temp->val>largest)largest=temp->val;
              if(temp->left!=NULL)q.push(temp->left);
              if(temp->right!=NULL)q.push(temp->right);
            }
            ans.push_back(largest);
        }
        return ans;
        
    }
};