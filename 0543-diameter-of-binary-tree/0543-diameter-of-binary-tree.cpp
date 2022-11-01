class Solution {
public:
    int maxi=0;
    int demo(TreeNode* root){
        if (root==NULL)return 0;
        int lh= demo(root->left);
        int rh= demo(root->right);
        maxi= max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        demo(root);
        return maxi;
    }
};