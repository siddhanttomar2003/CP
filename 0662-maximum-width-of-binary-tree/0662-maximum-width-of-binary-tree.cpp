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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        queue<pair<long long,TreeNode *>>q;
        q.push({0,root});
        long long maxi=1;
        int level=0;
        while(q.size()>0){
            long long s=0;long long e=0;
            int size=q.size();
            int mini=q.front().first;
            for(int i=0;i<size;i++){
                long long num=q.front().first-mini;
                TreeNode* curr=q.front().second;
                q.pop();
                if(i==0)s=num;
                if(i==size-1)e=num;
                if(curr->left!=NULL){
                    q.push({num*2*1ll+1,curr->left});
                }
                if(curr->right!=NULL){
                    q.push({num*2*1ll+2,curr->right});
                }
            }
            
            maxi=max(maxi,abs(e-s+1));

        }
        return maxi;
    }
};