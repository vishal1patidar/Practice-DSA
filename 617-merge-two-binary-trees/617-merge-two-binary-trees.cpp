class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // keeping the first tree as the primary tree
        if(root1 == nullptr && root2 == nullptr)
            return nullptr;
        if(root1 == nullptr && root2 != nullptr)
            return root2;
        if(root1 != nullptr && root2 == nullptr)
            return root1;
        if(root1 != nullptr && root2 != nullptr){
            root1->val += root2->val;
        }
        
        root1->right = mergeTrees(root1->right, root2->right);
        root1->left = mergeTrees(root1->left, root2->left);
        
        return root1;
    }
};