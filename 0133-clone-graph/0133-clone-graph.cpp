/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* &start, Node* &curr,set<Node *>&st,map<Node *,Node *>&mp, map<Node *, set<Node *>>&adj){
        st.insert(curr);
        for(auto it:curr->neighbors){
            if(st.find(it)==st.end()){
                Node *nxt=new Node(it->val);
                mp[it]=nxt;
                start->neighbors.push_back(nxt);
                nxt->neighbors.push_back(start);
                adj[start].insert(nxt);
                adj[nxt].insert(start);
                dfs(nxt,it,st,mp,adj);
            }
            else {
                
                 if(adj[mp[it]].find(start)==adj[mp[it]].end()){
                    adj[mp[it]].insert(start);
                    mp[it]->neighbors.push_back(start);
                 }
                 if(adj[start].find(mp[it])==adj[start].end()){
                    adj[start].insert(mp[it]);
                    start->neighbors.push_back(mp[it]);
                 }
                
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        set<Node *>vis;
        Node *start= new Node(node->val);
        Node *par = NULL;
        map<Node *, Node *>mp;
        mp[node]=start;
        map<Node *,set<Node *>>adj;
        dfs(start,node,vis,mp,adj);
        return start;
    }
};
