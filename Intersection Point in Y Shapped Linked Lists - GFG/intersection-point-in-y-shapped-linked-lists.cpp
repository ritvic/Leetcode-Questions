// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
int length(Node*head)
{
    Node*ptr=head;
    int cnt=0;
    while(ptr->next!=NULL)
    {
        cnt++;
        ptr=ptr->next;
    }
    return cnt;
}
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int cnt1=length(head1);
    int cnt2=length(head2);
    int diff=abs(cnt1-cnt2);
    Node*ptr1=head1;
    Node*ptr2=head2;
    if(cnt1>cnt2)
    {
        for(int i=0;i<diff;i++)
        {
            ptr1=ptr1->next;
        }
    }
    if(cnt2>cnt1)
    {
        for(int i=0;i<diff;i++)
        {
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=ptr2)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return ptr1->data;
}

