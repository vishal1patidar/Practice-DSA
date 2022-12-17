/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
   Node* copyRandomList(Node* head) {
	Node* tmp1 = head;
	Node* head2 = NULL;
	Node* tmp2 = head2;
	unordered_map<Node*,Node*> m;
	while(tmp1){
		if(head2 == NULL){
			head2 = new Node(head->val);
			tmp2 = head2;
			tmp1 = tmp1->next;
			continue;
		}

		tmp2->next = new Node(tmp1->val);
		tmp2 = tmp2->next;
		tmp1 = tmp1->next;
	}
	tmp1 = head;
	tmp2 = head2;
	while(tmp1){
		m[tmp1] = tmp2;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}

	tmp1 = head;
	tmp2 = head2;
	while(tmp1){
		Node* dummy = tmp1->random;
		tmp2->random = m[dummy];
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return head2;
}
};