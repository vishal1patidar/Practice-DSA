class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans1;
        if(root == NULL)
            return ans1;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> ans2(size);
            
            //level process
            for(int i = 0 ; i < size ; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                int index = leftToRight ? i : size - i - 1;
                ans2[index] = temp->val;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            //direction reversal
            leftToRight = !leftToRight;
            ans1.push_back(ans2);
        }
        return ans1;
    }
};