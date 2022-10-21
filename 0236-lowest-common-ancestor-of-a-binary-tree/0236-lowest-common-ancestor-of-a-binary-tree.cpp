class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root)
            return root;
        
		// If p or q if found, return the root.
        if (root == p || root == q)
            return root;
        
		// Save the root found at left and right recursively
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
		// If both the nodes are found, return parent of that node. That will be root.
        if (left && right)
            return root;
        // If left is found, and right is not found.
		// It is given that both the p and q will exist for sure.
		// If left present then right will be a decendent of left, or vice versa.
        return left? left: right;
    }
};