
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int noOfCam = 0;
        int ans = helper(root, noOfCam);
        
        if(ans == -1)   //we need to fix a camera
            noOfCam++;
        
        return noOfCam;
    }
    
    int helper(TreeNode* root, int &noOfCam){
        if(root== NULL) //I am not even a node, Tell them I dont need cam at all
            return 1;
        
        int left = helper(root->left, noOfCam);
        int right = helper(root->right, noOfCam);
        
        //child wants camera, install 1 cam there
        if(left==-1 || right==-1){
            noOfCam++;
            return 0;   //tell cam is installed here
        }
        
        //if at any node cam is installed, tell them we dont need cam here
        if(left==0 || right==0)
            return 1;
        
        //1-> this node is not covered go and tell parent please install a cam
        return -1;
        
    }
};
//TC = O(N) for dfs
//SC = O(N) recursion stack space

