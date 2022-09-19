class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        ListNode* headNext = head->next;
        headNext->next = head;
        head->next = NULL;
        return newHead;
    }
};