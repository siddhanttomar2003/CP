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
        int curr_x=0;int curr_y=0;
        map<int,map<int,multiset<int>>>mp;
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<pair<int,TreeNode*>>q;
        q.push({curr_x,root});
        while(q.size()>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *curr=q.front().second;
                int x=q.front().first;
                q.pop();
                mp[x][curr_y].insert(curr->val);
                if(curr->left!=NULL){
                    q.push({x-1,curr->left});
                }
                if(curr->right!=NULL){
                    q.push({x+1,curr->right});
                }
            }
            curr_y++;
        }
        for(auto it:mp){
            vector<int>temp;
            for(auto it2:it.second){
                   for(auto it3:it2.second){
                    temp.push_back(it3);
                   }
            }
            // reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
        
    }
};