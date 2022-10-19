class Solution {

public:
    vector<vector<int>> answer;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);// using dfs to traverse on each node
        return answer;
    }
    void dfs(TreeNode* root, int newtarget, vector<int>& path) {
        if (!root) return; // if current root is null return
        path.push_back(root->val);
        newtarget -= root->val; // new target will be the privious target- the value of that node
        if (!root->left && !root->right) { // check whether it is a leaf node or not
            if (newtarget == 0) // if we get valid path, pushback in our answer
                answer.push_back(path);
        } else {
            dfs(root->left, newtarget, path);
            dfs(root->right, newtarget, path);
        }
        path.pop_back(); // for the backtracking
    }
};