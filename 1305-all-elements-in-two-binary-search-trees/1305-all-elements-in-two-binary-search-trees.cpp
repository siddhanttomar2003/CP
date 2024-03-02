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
    void recur(TreeNode *root,vector<int> &v){
        if(root==NULL)return;
        recur(root->left,v);
        v.push_back(root->val);
        recur(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        vector<int>v1;
        vector<int>v2;
        recur(root1,v1);
        recur(root2,v2);
        int i=0; int m=v1.size();
        int j=0;  int n=v2.size();
        while(i<m &&j<n){
            if(v1[i]<v2[j]){
            ans.push_back(v1[i]);
            i++;
            }
            else if(v1[i]==v2[j]){
                ans.push_back(v1[i]);
                ans.push_back(v2[j]);
                i++;j++;
            }
            else {
                ans.push_back(v2[j]);
                j++;
            }
        }
        while(i<m){
            ans.push_back(v1[i]);i++;
        }
        while(j<n){
            ans.push_back(v2[j]);j++;
        }
        return ans;
    }
};