// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
static int postindex=0;
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
    Node* build(int in[],int post[],int s,int e)
    {
        
        if(s>e)
        return NULL;
        Node* head=new Node(post[postindex--]);
        if(s==e)
        return head;
        int mid=search(in,s,e,head->data);
        head->right=build(in,post,mid+1,e);
        head->left=build(in,post,s,mid-1);
        
        return head;
    }
    Node* buildTree(int in[],int post[], int n)
    {
        // Code here
        postindex=n-1;
        return build(in,post,0,n-1);
    }
