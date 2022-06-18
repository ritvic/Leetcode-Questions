// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    vector <int> v;
    while(head){
        v.push_back(head->data);
        head = head->next;
    }
    int n = v.size(), c = 0;
    if(v[0] > v[n-1])
        reverse(v.begin(), v.end());
    for(int i=0; i<n-2; i++){
        int l = i+1, r = n-1, s = x-v[i];
        while(l < r){
            if(v[l] + v[r] < s)
                l += 1;
            else if(v[l] + v[r] > s)
                r -= 1;
            else{
                c += 1;
                l += 1;
                r -= 1;
            }
        }
    }
    return c;
} 