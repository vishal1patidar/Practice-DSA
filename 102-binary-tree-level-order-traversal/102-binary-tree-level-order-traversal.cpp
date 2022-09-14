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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (root==NULL){
            return res;
        }
        
        queue<TreeNode*> nodeq;
        nodeq.push(root);
        
        while(!nodeq.empty()){
            int size = nodeq.size();
            vector<int> row(size);
            
            for(int i=0;i<size;i++){
                TreeNode* node = nodeq.front();
                nodeq.pop();
                
                row[i] = node->val;
                
                if(node->left){
                    nodeq.push(node->left);
                }
                if(node->right){
                    nodeq.push(node->right);
                }
            }
            
            res.push_back(row);
        }
        
        return res;
    }
};