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
    TreeNode *construct(vector<int>&pre, vector<int>&in, map<int,int>&mp, int pre_start,int pre_end, int in_start, int in_end){
        if(pre_start>pre_end || in_start>in_end)return NULL;
        if(pre_start==pre_end && in_start==in_end)return new TreeNode (pre[pre_start]);
        // root=current pre range first element
        int ind=mp[pre[pre_start]];
        TreeNode *curr=new TreeNode(pre[pre_start]);
        int range_left=ind-in_start;
        curr->left=construct(pre,in,mp,pre_start+1,pre_start+range_left,in_start,ind-1);
        curr->right=construct(pre,in,mp,pre_start+range_left+1,pre_end,ind+1,in_end);
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int n=preorder.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return construct(preorder,inorder,mp,0,n-1,0,n-1);
    }
};