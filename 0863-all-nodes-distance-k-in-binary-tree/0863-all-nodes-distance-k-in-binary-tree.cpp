/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void nodeToParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left != NULL) {
                    q.push(temp->left);
                    mp[temp->left] = temp;
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                    mp[temp->right] = temp;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        unordered_map<TreeNode*, TreeNode*> parent_mapping;
        nodeToParent(root, parent_mapping);
        queue<TreeNode *> q;
        unordered_map<TreeNode *, bool> visited;
        q.push(target);
        visited[target] = true;
        int current_level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (current_level++ == k)  break;
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL&&!visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right!=NULL &&!visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right]=true;     
                }
                if(parent_mapping[temp]&&!visited[parent_mapping[temp]]){
                    q.push(parent_mapping[temp]);
                    visited[parent_mapping[temp]]=true;
                }


            }
        }
        while(!q.empty()){
            TreeNode *temp=q.front();
            ans.push_back(temp->val);
            q.pop();
        }
        return ans;
    }
};