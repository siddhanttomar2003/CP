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
 #define ll long long
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll>sum;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            ll curr_sum=0;
            for(int i=0;i<size;i++){
                TreeNode *temp=q.front();q.pop();
                curr_sum+=temp->val;
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
            }
            sum.push_back(curr_sum);
        }
         if(sum.size()<k)return -1;
         sort(sum.rbegin(),sum.rend());
         return sum[k-1];
    }
};