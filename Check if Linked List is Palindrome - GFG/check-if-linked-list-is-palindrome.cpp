// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* midn(Node *head){
       Node *slow=head, *fast=head;
       while(fast->next && fast->next->next){
           slow=slow->next;
           fast=fast->next->next;
       }
       return slow;
   }
   Node *reverse(Node *head){
       Node *prev=NULL,*curr=head,*fwd=NULL;
       while(curr!=NULL){
           fwd=curr->next;
           curr->next=prev;
           prev=curr;
           curr=fwd;
       }
       return prev;
   }
   bool isPalindrome(Node *head)
   {
       //Your code here
       Node *mid=midn(head);
       Node *first=head;
       Node *last=reverse(mid->next);
       mid->next=NULL;
       while(last!=NULL){
           if(last->data!=first->data) return false;
           first=first->next;
           last=last->next;
       }
       return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends