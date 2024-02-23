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
    int recur(TreeNode * root,unordered_map<int,int> &mp){
        int sum=0;
     if(root==NULL)return 0;
       sum+=recur(root->left,mp);
      sum+= recur(root->right,mp);
      sum+=root->val;
      mp[sum]++;
      return sum;
      
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        unordered_map<int,int>mp;
        recur(root,mp);
        int maxi_times=0;
        for(auto it:mp){
            if(it.second>maxi_times)maxi_times=it.second;
        }
        for(auto it:mp){
            if(it.second==maxi_times)ans.push_back(it.first);
        }
        return ans;

    }
};