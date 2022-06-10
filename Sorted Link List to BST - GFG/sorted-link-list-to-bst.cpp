// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


 // } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
        TNode* fun(vector<int>&arr,int low,int high){
            if(low>high)
            return NULL;
            int mid;
            // TNode* head=NULL;
            if(low<=high)
            {
                mid = ceil(float(high+low)/2);
                TNode* head=new TNode(arr[mid]);
                TNode* left=fun(arr,low,mid-1);
                TNode* right=fun(arr,mid+1,high);
                head->left=left;head->right=right;
                return head;
            }
        }
        
    TNode* sortedListToBST(LNode *head) {
        
        LNode* temp=head;
        vector<int> v;
        while(temp)
        {
            v.push_back(temp->data);
            temp=temp->next;
        }
        TNode* t= fun(v,0,v.size()-1);
        return t;
        //code here
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends