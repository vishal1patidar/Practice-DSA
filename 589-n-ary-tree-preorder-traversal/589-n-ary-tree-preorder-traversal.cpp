class Solution {
public:
	vector<int> preorder(Node* root) {
		vector<int> res;
		function<void(Node*)> recur=[&](Node* root){
			if(!root) return;
			res.push_back(root->val);
			for(int i=0;i<root->children.size();i++) {
				recur(root->children[i]);
			}
		};
		recur(root);
		return res;
	}
};