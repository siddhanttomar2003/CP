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
    typedef long long ll;
    const int mod = 1e9 + 7;
    ll ans;
    ll cal(TreeNode * root){
        if(root == NULL)return 0;
        ll curr = root -> val;
        ll l = cal(root -> left);
        ll r = cal(root -> right);
        return curr + l + r;
    }
    ll f_ans(TreeNode * root, ll sum){
        if(root == NULL)return 0;
        ll curr = root -> val;
        ll l = f_ans(root -> left, sum);
        ll r = f_ans(root -> right, sum);
        ll a = (sum - (curr + l + r)) * (curr + l + r);
        ll b =  (sum - l) * l;
        ll c =  (sum - r) * r;
        // cout << a << b << c << endl;
        ans = max({ans, a, b, c});
        return curr + l + r;
    }
    int maxProduct(TreeNode* root) {
        ans = -1;
        TreeNode * temp = root;
        ll sum = cal(root);
        f_ans(temp, sum);
        return ans % mod;
    }
};