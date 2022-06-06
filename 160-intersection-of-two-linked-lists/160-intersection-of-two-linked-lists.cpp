/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1=headA;
        ListNode* t2=headB;
        int l1=1;
        int l2=1;
        while (t1->next){
            l1+=1;
            t1=t1->next;
        }
        while (t2->next){
            l2+=1;
            t2=t2->next;
        }
        if (t1!=t2){
            return NULL;
        }
        int move1 = max(0,l1-l2);
        int move2 = max(0,l2-l1);
        while (move1>0){
            headA=headA->next;
            move1--;
        }
        while (move2>0){
            headB=headB->next;
            move2--;
        }
        while (headA!=headB){
            headB=headB->next;
            headA=headA->next;
        }
        return headA;
    }
};