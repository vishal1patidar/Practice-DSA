class Solution 
{
   public:
   	int maxDepth(TreeNode* root) 
   	{
   		if(!root)           //end reached
   			return 0;
           
   		int left = maxDepth(root->left);    //go left
   		int right = maxDepth(root->right);  //go right
           
   		return max(left, right) + 1;
   	}
};