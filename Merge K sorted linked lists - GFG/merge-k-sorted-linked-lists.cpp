// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* sortedMerge(Node* h1, Node* h2)  
    {  
    
        if (!h1)
            return h2;
        if (!h2)
            return h1;
     
        // start with the linked list
        // whose head data is the least
        if (h1->data < h2->data) {
            h1->next = sortedMerge(h1->next, h2);
            return h1;
        }
        else {
            h2->next = sortedMerge(h1, h2->next);
            return h2;
        }
    
    } 
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           Node* n=NULL;
           for(int i=0;i<K;i++){
               n=sortedMerge(n,arr[i]);
           }
           return n;
           

    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends