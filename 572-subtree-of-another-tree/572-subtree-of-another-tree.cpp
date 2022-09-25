class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        bool res = false;
        if (root->val == subRoot->val) {
            res = compare(root, subRoot);
        }
        return res ? res : isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool compare(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }
        if ((t1 == nullptr || t2 == nullptr) || t1->val != t2->val) {
            return false;
        }
        return compare(t1->left, t2->left) && compare(t1->right, t2->right);
    }
};