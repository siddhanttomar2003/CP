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
    int cal_subnodes(map<int,int>&sub_nodes,TreeNode *root){
        if(root==NULL)return 0;
        int l=cal_subnodes(sub_nodes,root->left);
        int r=cal_subnodes(sub_nodes,root->right);
        sub_nodes[root->val]=l+r;
        return l+r+1;
    }
    void cal_depth(map<int,int>&depth, TreeNode *root,int curr){
        if(root==NULL)return ;
        depth[root->val]=curr;
         cal_depth(depth,root->left,curr+1);
         cal_depth(depth,root->right,curr+1);
    }
    void pre(TreeNode *root, vector<pair<int,int>>&preorder,map<int,int>&depth){
        if(root==NULL)return;
        preorder.push_back({root->val,depth[root->val]});
        pre(root->left,preorder,depth);
        pre(root->right,preorder,depth);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        map<int,int>sub_nodes;
        map<int,int>depth;
        cal_depth(depth,root,0);
        cal_subnodes(sub_nodes,root);
        vector<pair<int,int>>preorder;
        pre(root,preorder,depth);
        // for(int i=0;i<preorder.size();i++){
        //     cout<<preorder[i].first<<"->"<<preorder[i].second<<" ";
        // }
        // cout<<endl;
        map<int,int>node_ind;
        for(int i=0;i<preorder.size();i++){
            node_ind[preorder[i].first]=i;
        }
        // for(auto it:depth){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        int n=preorder.size();

        vector<int>pre_max(n+1);
        vector<int>suf_max(n+1);
        pre_max[0]=0;
        suf_max[n]=0;
        for(int i=0;i<n;i++){
            int curr=preorder[i].second;
            int curr2=preorder[n-i-1].second;
             suf_max[n-i-1]=max(suf_max[n-i],curr2);
             pre_max[i+1]=max(pre_max[i],curr);
             
        }
        // for(int i=0;i<=n;i++)cout<<pre_max[i]<<" ";
        // cout<<endl;
        //         for(int i=0;i<=n;i++)cout<<suf_max[i]<<" ";
        // cout<<endl;
        vector<int>temp;
        for(int i=0;i<queries.size();i++){
            int parent=queries[i];
            int index=node_ind[parent];
            int del_range=sub_nodes[parent]+index;
            int ans=0;
            ans=max(ans,pre_max[index]);
            // cout<<index+del_range+1<<endl;
            ans=max(ans,suf_max[del_range+1]);
            temp.push_back(ans);
        }
        return temp;
    }
};