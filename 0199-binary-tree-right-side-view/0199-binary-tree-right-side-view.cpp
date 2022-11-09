class Solution {
public:
    void RightView(TreeNode* root, int level, vector<int>&ans)
    {
        if(root==NULL)
            return;
        
        if(level == ans.size())
            ans.push_back(root->val);
        
        RightView(root->right, level+1, ans);
        RightView(root->left, level+1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        RightView(root, 0, ans);
        
        return ans;
    }
};