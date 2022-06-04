// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

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

class Solution
{
    public:
    Node* reverse(Node* head)
    {
        struct Node *q=NULL,*r=NULL;
        while(head!=NULL)
        {
           r=q;
           q=head;
           head=head->next;
           q->next=r;
        }
        return q;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* temp=head;
        temp=reverse(temp);
        // return temp;
        Node* temp1=temp,*t=temp;
        temp->data+=1;
        int c=0,s=0;
        while(temp1)
        {
            s=temp1->data+c;
            if(s>=10)
            {
                temp1->data=s%10;
                c=1;
            }
            else
            {
                c=0;temp1->data=s;
            }
            temp1=temp1->next;
            if(t->next)
            t=t->next;
        }
        if(c==1)
        {t->next=new Node(1);}
        temp=reverse(temp);
        return temp;
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends