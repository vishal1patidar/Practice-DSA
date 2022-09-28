class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode *slow = start , *fast = start;
        
        for(int i = 0 ; i <= n ; i++) {
            fast = fast->next;
        }
        
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
};