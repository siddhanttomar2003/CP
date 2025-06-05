/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void serialize(TreeNode* root, string& s) {
        if (root == NULL) {
            s += ",#";
            return;
        }
        s += "," + to_string(root->val);
        serialize(root->left, s);
        serialize(root->right, s);
    }
    void build_lps(string& s, int n, vector<int>& lps) {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < n) {
            if (s[len] == s[i]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    i++;
                }
            }
        }
    }
    bool matching(string& s1, string& s2, vector<int>& lps) {
        int n = s1.size(), m = s2.size();
        int i = 0, j = 0;
        while (i < n) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
                if (j == m)
                    return true;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else
                    i++;
            }
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1, s2;
        serialize(root, s1);
        serialize(subRoot, s2);
        int m = s2.size();
        vector<int> lps(m, 0);
        build_lps(s2, m , lps);
        return matching(s1, s2, lps);
    }
};