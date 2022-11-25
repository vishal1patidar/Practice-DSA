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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root==NULL)return ans;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node* el= stk.top();
            stk.pop();
            ans.push_back(el->val);
            for (auto it= rbegin(el->children); it!=rend(el->children); it++){
                stk.push(*it);
            }
        }
        return ans;
    }
};