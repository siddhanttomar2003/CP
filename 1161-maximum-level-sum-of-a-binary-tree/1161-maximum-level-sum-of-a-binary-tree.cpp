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
    int maxLevelSum(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return 0;
        queue<TreeNode *>q;
        q.push(root);
        int pos=-1;
        int curr_level=1;
        int maxi=INT_MIN;
        while(!q.empty()){
            int size=q.size();
             int sum=0;
            for(int i=0;i<size;i++){
                TreeNode * temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=nullptr)q.push(temp->right);
            }
           if(sum>maxi){
               maxi=sum;
               pos=curr_level;
           }
           curr_level++;
        }
        return pos;
    }
};