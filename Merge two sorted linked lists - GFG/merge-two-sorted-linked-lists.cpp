// { Driver Code Starts
#include<iostream>
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

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node* t1=head1,*t2=head2,*t3=NULL,*t4;
    
    while(t1 && t2)
    {
        if(!t3)
        {
            if(t1->data<t2->data)
            {t3=new Node(t1->data);t1=t1->next;}
            else
            {t3=new Node(t2->data);t2=t2->next;}
            t4=t3;
            continue;
        }
        if(t1->data<t2->data)
        {
            t4->next=new Node(t1->data);t1=t1->next;
        }
        else
        {
            t4->next=new Node(t2->data);t2=t2->next;
        }
        t4=t4->next;
    }
    while(t1)
    {
        t4->next=new Node(t1->data);
        t1=t1->next;
        t4=t4->next;
    }
    while(t2)
    {
        t4->next=new Node(t2->data);
        t2=t2->next;
        t4=t4->next;
    }
    return t3;
    
}  