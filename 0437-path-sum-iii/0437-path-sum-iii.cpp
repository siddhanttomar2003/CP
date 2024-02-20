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
    void recur(TreeNode *root, int targetSum, unordered_map<long long,int> &mp,int &count,long long sum){
        if(root==NULL)return;
        sum+=root->val;
        if(mp.find(sum-targetSum)!=mp.end()){
             count+=mp[sum-targetSum];
         }
        mp[sum]++;
         recur(root->left,targetSum,mp,count,sum);
         recur(root->right,targetSum,mp,count,sum);
         mp[sum]--;

    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>mp;
        int count=0;
        long long sum=0;
        mp[0]=1;
        recur(root,targetSum,mp,count,sum);
        return count;
    }
};