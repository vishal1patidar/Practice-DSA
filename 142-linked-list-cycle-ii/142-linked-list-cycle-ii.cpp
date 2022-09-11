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
    ListNode *detectCycle(ListNode *head) 
    {
        if(!head || !head->next || !head->next->next) 
            return NULL;
        ListNode* f=head->next->next, *s=head->next;
        while(f && f!=s)
        {
            if(f->next)
            {
                f=f->next;
                s=s->next;
            }
            else
            {
                f=f->next;
                break;
            }
            f=f->next;
        }
        if(f==NULL) 
            return f;
        
        f=head;
        while(f!=s)
        {
            f=f->next;
            s=s->next;
        }
        return f;
    }
};