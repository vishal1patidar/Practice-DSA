class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
		//Initialize the two pointers at the head of linked list .
        ListNode* middle = head; 
        ListNode* temp = head;
        
		//Now every time, middle moves 1 step at a time while temp moves 2 steps at a time.
		//Whenfast pointer arrives at the end,slow pointer will arrive right in the middle of our linked list.
		
        while(temp && temp->next != NULL){
            
            middle = middle->next;
            temp = temp->next->next;
        }
        //Now just return the middle pointer .
        return (middle);
        
    }
};