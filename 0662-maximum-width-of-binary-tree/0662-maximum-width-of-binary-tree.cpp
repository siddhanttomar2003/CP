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
        queue<pair<TreeNode *,int>>q;
        q.push({root,0});
        int first,second;
        int ans=INT_MIN;
        while(!q.empty()){
            int mini=q.front().second;
            int size=q.size();
            for(int i=0;i<size;i++){
               unsigned long long  int curr_id=q.front().second-mini;
                if(i==0)first=q.front().second;
                if(i==size-1)second=q.front().second;
                TreeNode *temp=q.front().first;
                q.pop();
                if(temp->left!=NULL){
                    q.push({temp->left,2*curr_id+1});
                }
                if(temp->right!=nullptr){
                    q.push({temp->right,2*curr_id+2});
                }  
                             
            }
            ans=max(ans,second-first+1);
        }
        return ans;

    }
};