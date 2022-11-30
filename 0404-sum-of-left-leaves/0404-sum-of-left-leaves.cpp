class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root);
    
    void calcSumLeftNodes(TreeNode* root, bool goLeftBool);

private:
    int _sumLeftNodes{};
};
int Solution::sumOfLeftLeaves(TreeNode* root) {
    if (root->left != nullptr) {
        calcSumLeftNodes(root->left, true);
    }
    if (root->right != nullptr) {
        calcSumLeftNodes(root->right, false);
    }
    return _sumLeftNodes;
}
void Solution::calcSumLeftNodes(TreeNode* root, bool goLeftBool) {
    if (root->left == nullptr && root->right == nullptr && goLeftBool == true) {
        _sumLeftNodes+=root->val;
        return;
    } 
    if (root->left != nullptr) {
        calcSumLeftNodes(root->left, true);
    }
    if (root->right != nullptr) {
        calcSumLeftNodes(root->right, false);
    }
    return;
}