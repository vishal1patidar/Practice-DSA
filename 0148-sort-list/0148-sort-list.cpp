class Solution {
public:
    // function that divides linked list into half parts, and after sorting use to merge them
    void mergesorting(ListNode** head) 
    {
        ListNode* curr = *head; // make a current pointer 
        ListNode* first; // for the first half
        ListNode* second; // for the second half
        
        // if linked list is null or just having a single elemrnt then simple return. because we don't have to do anything
        if(curr == NULL || curr -> next == NULL)
            return;
        
        findmid(curr, &first,&second); // function used to find mid in b/w the
        
        //again call merrge sorting for first half, so it again divides first half into two and for that again....till when only one element is left
        mergesorting(&first); 
        
        //again call merrge sorting for second half, so it again divides second half into two and for that again....till when only one element is left
        mergesorting(&second);
        
        *head = merge(first,second); // and at last merge oyr first half and second half
    }
    
    // function to find mid, we use hare and tortise meethod to find mid
    void findmid(ListNode* curr, ListNode** first, ListNode** second)
    {
        ListNode* slow = curr; // make a slow pointer
        ListNode* fast = curr -> next; // make a fast pointer
        
        // then we move our fast upto it not become null, means not reach on last position
        while(fast != NULL)
        {
            fast = fast -> next;
            if(fast != NULL)
            {
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        
        // after this assign curr to first
        *first = curr;
        *second = slow -> next; // second to slow next
        slow -> next = NULL; // and put slow next to null
    }
    
    // function used to merge first and second pointer
    ListNode* merge(ListNode* first, ListNode* second)
    {
        ListNode* answer = NULL; // define answer to null
        
        if(first == NULL) // if first is null, then what to merge...nothing
        {
            return second; // return second
        }
        
        if(second == NULL) // if second is null, then what to merge...nothing
        {
            return first; // return first
        }
        
        // if value of first is less than value of second,then give answer to first
        if(first -> val <= second -> val) 
        {
            answer = first;
            answer -> next = merge(first -> next, second); // and again call merge for answer's next
        }
        else // else give answer to second
        {
            answer = second;
            answer -> next = merge(first, second -> next); // and again call merge for answer's next
        }
        
        return answer; // finally return answer
    }
    ListNode* sortList(ListNode* head) {
        // paasing pointer as reference, so that changes are reflected
        mergesorting(&head); 
        
        return head;
    }
};