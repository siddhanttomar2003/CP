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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<Node *>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        while(!q.empty()){
            if(q.front()==NULL){
               ans.push_back(v);
               v.clear();
               q.pop();
               if(!q.empty())
                q.push(NULL);
                
            }
            else{
                Node *temp=q.front();
                v.push_back(temp->val);
                q.pop();
                for(int i=0;i<temp->children.size();i++){
                    q.push(temp->children[i]);
                }
            }
        }
        return ans;

    }
};