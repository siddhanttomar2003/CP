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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL)return nullptr;
        vector<vector<int>>v;
        queue<TreeNode *>q;
        q.push(root);
        int curr_level=0;
        while(!q.empty()){     
            int size=q.size();
            vector<int>ans(size);
            for(int i=0;i<size;i++){
             TreeNode *temp=q.front();
             q.pop();
             if(curr_level&1){
                 ans[size-i-1]=temp->val;
             }
             else{
                 ans[i]=temp->val;
             }
             if(temp->left!=NULL)q.push(temp->left);
             if(temp->right!=NULL)q.push(temp->right);
            }
            curr_level++;
            v.push_back(ans);
        }
        queue<TreeNode *>qs;
        qs.push(root);
        int curr=0;
        while(!qs.empty()){
            int size=qs.size();
             for(int i=0;i<size;i++){
                 qs.front()->val=v[curr][i];
                 TreeNode *temp=qs.front();qs.pop();
                 if(temp->left!=NULL)qs.push(temp->left);
                 if(temp->right!=NULL)qs.push(temp->right);
             }
             curr++;
        }
        return root;

    }
};