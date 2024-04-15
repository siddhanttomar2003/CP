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
    void recur(TreeNode* root,long long &sum,vector<long long>&ans){
        if(root==NULL)return ;
        sum=sum*10+root->val;
        if(root->left==NULL&&root->right==NULL){
            ans.push_back(sum);
            sum/=10;
            return;
        }
        recur(root->left,sum,ans);
        recur(root->right,sum,ans);
        sum/=10;

    }
    int sumNumbers(TreeNode* root) {
        vector<long long>ans;
        long long sum=0;
        recur(root,sum,ans);
        int final_ans=0;
        for(int i=0;i<ans.size();i++){
            final_ans+=ans[i];
        }
        return final_ans;
    }
};