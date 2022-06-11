// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node* reverse(Node* l2)
{
   if(l2==NULL)
   return NULL;
   Node* prev=NULL;
   Node* curr=l2;
   Node* nxt=curr->next;
   while(curr!=NULL)
   {
       nxt=curr->next;
       curr->next=prev;
       prev=curr;
       curr=nxt;
       
   }
   return prev;
   
}
void merge(Node* l1,Node* l2)
{
   while(l2!=NULL)
   {
       Node* nxt=l1->next;
       l1->next=l2;
       l1=l2;
       l2=nxt;
       
       
   }
   
   
}
void reorderList(Node* head) {
   // Your code here
   if(head==NULL||head->next==NULL)
   {
       return ;
   }
   Node* slow=head;
   Node* fast=head;
   Node* prev=head;
   while(fast&&fast->next)
   {
       prev=slow;
       slow=slow->next;
       fast=fast->next->next;
   }
   prev->next=NULL;
   Node* l1=head;
   Node* l2=reverse(slow);
   merge(l1,l2);
   
}