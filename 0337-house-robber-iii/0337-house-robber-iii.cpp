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
    map<TreeNode *,map<int,int>>mp;
    int cal(TreeNode * root, int state){
        if(root == NULL)return 0;
        if(mp.find(root) != mp.end() && mp[root].find(state) != mp[root].end())return mp[root][state];
        int ans = 0;
        if(state == 0){
        ans = max(root -> val + cal(root -> left, state ^ 1) + cal(root -> right, state ^ 1), cal(root -> left, state) + cal(root -> right , state));
        }
        else {
            ans += cal(root -> left, state ^ 1);
            ans += cal(root -> right, state ^ 1);
        }
        return mp[root][state] = ans;
    }
    int rob(TreeNode* root) {
        int state = 0;
        return max(cal(root, state), cal(root, state ^ 1));
    }
};