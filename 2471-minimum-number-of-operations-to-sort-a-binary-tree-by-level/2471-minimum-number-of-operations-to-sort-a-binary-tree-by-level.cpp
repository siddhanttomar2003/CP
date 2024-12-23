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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode *>q;
        if(root==NULL)return 0;
        q.push(root);
        int ans=0;
        while(q.size()>0){
            int size=q.size();
            vector<int>temp;
            for(int i=0;i<size;i++){
                TreeNode * curr=q.front();
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                    temp.push_back(curr->left->val);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                    temp.push_back(curr->right->val);
                }
            }
            map<int,int>mp;
            for(int i=0;i<temp.size();i++){
                mp[temp[i]]=i;
            }
            vector<int>v=temp;
            sort(v.begin(),v.end());
           for(int i=0;i<v.size();i++){
                if(temp[i]!=v[i]){
                    int pos=mp[v[i]];
                     temp[pos]=temp[i];
                     mp[temp[i]]=pos;
                     temp[i]=v[i];
                     ans++;
                }
                cout<<temp[i]<<" ";
           }
           cout<<endl;
          
            
        }
        return ans;
    }
};