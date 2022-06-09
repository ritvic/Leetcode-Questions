// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


class Trie{
public:
    Trie* next[2];
    Trie()
    {
        next[0]=next[1]=NULL;
    }
};
void insert(Trie* head,int val)
{
    Trie* curr=head;
    for(int i=31;i>=0;i--)
    {
        int bit=(val>>i)&1;
        if(!curr->next[bit])
        curr->next[bit]=new Trie();
        curr=curr->next[bit];
    }
}


int findMaxXorSubarray(Trie* head,int arr[],int n){
    int max_xor = INT_MIN;
    for(int j=0;j<n;j++){
        int val = arr[j];
        int curr_xor = 0;
        Trie* curr = head;
        for(int i=31;i>=0;i--){
            int bit = (val>>i)&1;
            int oppo = !bit;
            if(curr->next[oppo])
                curr_xor |= 1<<i,curr = curr->next[oppo];
            else
                curr = curr->next[!oppo];
        }
        max_xor = max(max_xor,curr_xor);
    }
    return max_xor;
}

class Solution{   
public:
    int maxSubarrayXOR(int n, int arr[]){
        Trie* head = new Trie();
       int v[n+1] = {0};
       v[1] = arr[0];
       insert(head,v[0]);
         for(int i=1;i<n;i++){
             v[i+1] = v[i]^arr[i];
             insert(head,v[i]);
        }
        return findMaxXorSubarray(head,v,n+1);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends