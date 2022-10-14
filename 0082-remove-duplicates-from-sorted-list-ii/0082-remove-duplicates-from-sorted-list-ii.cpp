/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //if head is NULL or just having a single node, simply return from here head 
        if(head == NULL || head->next == NULL) 
            return head;
        
        // creating our dummy node i.e prehead
        // we are giving it's value is -101, because see constraints
        // -100 <= Node.val <= 100
        ListNode* prehead = new ListNode(-101);
        
        prehead -> next = head; // prehead's next contain head
        
        ListNode* curr = prehead; // make a current pointer to move
        
        // while it not reaches to the end
        while(curr -> next != NULL && curr -> next -> next != NULL)
        {
            // if values are equal, now we have to delete values, till when they are equal
           if(curr -> next -> val == curr -> next -> next -> val)
           {
               // temp pointer to find upto when the va;ues are equal and delete that nodes which ar not be include in our answer
               ListNode* temp = curr -> next -> next;
               while(temp != NULL && curr -> next -> val == temp -> val)
               {
                   ListNode *anthortemp = temp;
                   temp = temp -> next;
                   delete anthortemp; // actually freeing up the memory
               }
               curr -> next = temp;
           }
           else // if values are not equal's then simply move curr to next
           {
               curr = curr -> next;
           }
        }
        
        // and at last, prehead's next contain head node, so return that
        return prehead -> next;
        
    }
};