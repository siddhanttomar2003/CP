/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void cal(vector<int>&ans, Node *root){
        Node *curr=root;
        if(curr==NULL)return ;
        for(int i=0;i<curr->children.size();i++){
            cal(ans,curr->children[i]);
        }
        ans.push_back(curr->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>ans;
        cal(ans,root);
        return ans;
    }
};