class Solution {
public:
    TreeNode* recoverFromPreorder(string t) {
        int n = t.size();
        map<int, TreeNode*> mp;
        int i = 0;

        string temp = "";
        while (i < n && isdigit(t[i])) {
            temp += t[i];
            i++;
        }
        int num = stoi(temp);
        TreeNode* root = new TreeNode(num);
        mp[0] = root;
        temp = "";

        while (i < n) {
            int depth = 0;
            while (i < n && t[i] == '-') {
                depth++;
                i++;
            }

            temp = "";
            while (i < n && isdigit(t[i])) {
                temp += t[i];
                i++;
            }

            if (temp.empty()) continue;

            num = stoi(temp);
            TreeNode* node = new TreeNode(num);

            if (mp.find(depth - 1) == mp.end()) return nullptr;

            TreeNode* parent = mp[depth - 1];
            if (parent->left == NULL)
                parent->left = node;
            else
                parent->right = node;

            mp[depth] = node;
        }

        return root;
    }
};
