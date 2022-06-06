// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
void assign(Node* &head, Node* &tail, Node* ptr) {
    if (ptr == NULL)
        return;
    if (head == NULL) {
        head = ptr;
        tail = ptr;
    }
    else{
        tail -> bottom = ptr;
        tail = tail -> bottom;
    }
}
Node* mergeList(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* tail = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1 -> data <= head2 -> data) {
            assign(head, tail, head1);
            head1 = head1 -> bottom;
        }
        else {
            assign(head, tail, head2);
            head2 = head2 -> bottom;
        }
    }
    if (head1 == NULL) assign(head, tail, head2);
    if (head2 == NULL) assign(head, tail, head1);
    return head;
    
}
Node *flatten(Node *root)
{
   // Your code here
   Node* head = NULL;
   Node* ptr = root;
   Node* next = NULL;
   while (ptr != NULL) {
       next = ptr -> next;
       ptr -> next = NULL;
       head = mergeList(head, ptr);
       ptr = next;
   }
   return head;
}

