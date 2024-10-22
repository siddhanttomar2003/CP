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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*, int> visited;
        
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left != NULL) {
                    mp[curr->left] = curr;
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    mp[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        q.push(target);
        visited[target]++;
        while (q.size() > 0 && k > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left != NULL &&
                    visited.find(curr->left) == visited.end()) {
                    visited[curr->left]++;
                    q.push(curr->left);
                }
                if (curr->right != NULL &&
                    visited.find(curr->right) == visited.end()) {
                    visited[curr->right]++;
                    q.push(curr->right);
                }
                if (mp.find(curr) != mp.end() &&
                    visited.find(mp[curr]) == visited.end()) {
                    visited[mp[curr]]++;
                    q.push(mp[curr]);
                }
            }
            k--;
        }
        while (q.size() > 0) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};