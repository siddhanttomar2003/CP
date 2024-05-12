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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode *,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>mp;// first outer map to store according to verticals as defined in notes
        // second inner map is to store according to the levels;
            q.push({root,{0,0}});
            mp[0][0].insert(root->val);
            while(q.size()>0){
              int size=q.size();
              for(int i=0;i<size;i++){
                TreeNode *temp=q.front().first;
                int vertical=q.front().second.first;
                int level=q.front().second.second;
                q.pop();
                if(temp->left!=NULL){
                    q.push({temp->left,{vertical-1,level+1}});
                    mp[vertical-1][level+1].insert(temp->left->val);
                }
                if(temp->right!=NULL)
                {
                    q.push({temp->right,{vertical+1,level+1}});
                    mp[vertical+1][level+1].insert(temp->right->val);
                }
              }
            }
            vector<vector<int>>ans;
            for(auto it1:mp){
                vector<int>ver;
                for(auto it2:it1.second){
                   for(auto it3:it2.second){
                    ver.push_back(it3);
                   }
                }
                ans.push_back(ver);
            }
            return ans;
    }
};