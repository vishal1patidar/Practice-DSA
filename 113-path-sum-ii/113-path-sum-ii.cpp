class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> path;
    
    void dfs(TreeNode* root, int current, int target) {
        if(!root) {
            return;
        }
        
        current += root->val;
        path.push_back(root->val);
        
		// When we reach at leaf node, we have to check if current sum is equal to target
        if(current == target && !root->left && !root->right) {
            ans.push_back(path);
        }    
        
        dfs(root->left, current, target);
        dfs(root->right, current, target);
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return ans;
    }
};