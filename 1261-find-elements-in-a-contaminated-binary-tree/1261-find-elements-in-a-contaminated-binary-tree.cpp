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
class FindElements {
public:
    set<long long>st;
    
    FindElements(TreeNode* root) {
        cal_ele(root,0);
    }
    void cal_ele(TreeNode *root, long long i){
        if(root==NULL)return ;
        if(2*i+1<=1e6){
        cal_ele(root->left,2*i+1);
        cal_ele(root->right,2*i+2);
        }
        st.insert(i);
    }
    bool find(int target) {
        if(st.find(target)!=st.end())return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */