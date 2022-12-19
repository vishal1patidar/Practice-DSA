class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int c=0;
        ListNode *A=head;
        if(A==NULL || A->next==NULL || k==0) return A;
        while(A)
        {
            c++;
            A=A->next;
        }
        k=k%c;
        if(k==0)return head;
        k=c-k;
        int n=0;
        A=head;
        ListNode * x,*y,*prv=NULL;
        cout<<k<<endl;
        while(A)
        {
            n++;
            if(n==k)
            {
                y=A;
                x=A->next;
            }
            prv=A;
            A=A->next;
        }
        y->next=NULL;
        prv->next=head;
        return x;
    }
};