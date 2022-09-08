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
    vector<int> inorder;
    void findInorder(TreeNode* root){
        if(root==NULL)
            return ;
        findInorder(root->left);
        inorder.push_back(root->val);
        findInorder(root->right);
        
    }
    bool findTarget(TreeNode* root, int k) {
        
        findInorder(root);
        int n=inorder.size();
        if(n==1)
            return false;
        int start=0;
        int end=n-1;
        while(start<end){
            if(inorder[start]+inorder[end]==k)
                return true;
            if(inorder[start]+inorder[end]>k)
                end--;
            if(inorder[start]+inorder[end]<k)
                start++;
        }
        return false;
    }
};