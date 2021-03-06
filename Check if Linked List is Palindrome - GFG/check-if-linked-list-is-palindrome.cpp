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
   Node* findmid(Node* head)
   {
       Node* slow=head,*fast=head;
       while(fast && fast->next)
       {
           slow=slow->next;
           fast=fast->next->next;
       }
       return slow;
   }
//   struct Node *q=NULL,*r=NULL;
//       while(head!=NULL)
//       {
//           r=q;
//           q=head;
//           head=head->next;
//           q->next=r;
//       }
//     //   free(head);
//     //   free(r);
//       return q;
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
    //   free(head);
    //   free(r);
      return q;
   }
   bool isPalindrome(Node *head)
   {
       //Your code here
       Node *mid=findmid(head);
       Node *new_head=reverse(mid);
       while(head!=mid)
       {
           if(head->data==new_head->data)
           {
               head=head->next;
               new_head=new_head->next;
           }
           else
               return false;
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