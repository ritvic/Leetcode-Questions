// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


static int preindex=0;
class Solution{
    public:
    int search(int arr[], int s, int e, int value)
    {
        int j;
        for (int i = s; i <= e; i++)
        {
            if (arr[i] == value)
                j=i;
        }
        return j;
    }
    Node* build(int in[],int pre[],int s,int e)
    {
        
        if(s>e)
        return NULL;
        Node* head=new Node(pre[preindex++]);
        if(s==e)
        return head;
        int mid=search(in,s,e,head->data);
        head->left=build(in,pre,s,mid-1);
        head->right=build(in,pre,mid+1,e);
        
        return head;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        preindex=0;
        return build(in,pre,0,n-1);
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends