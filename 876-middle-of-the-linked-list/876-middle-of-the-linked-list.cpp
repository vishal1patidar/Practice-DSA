class Solution {
public:
ListNode* middleNode(ListNode* head) {
if (!head->next) { return head; }
if (!head->next->next) { return head->next; }
ListNode *slow = head, *fast = head;
while (fast && fast->next) { slow = slow->next, fast = fast->next->next; }
return slow;
}
};