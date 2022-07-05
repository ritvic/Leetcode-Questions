// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int N)
    {
        // Your code here
         int bit = 0; 
         int count = 0; 
         for (int i=30;i>=0;i--) { 
             bit |= 1<<i; 
             for (int j=0;j<N;j++) { 
                 if ((bit&arr[j]) == bit) {count++;} 
             }
             if (count < 2) {bit = bit&(bit-1);} 
             count=0; 
         }
         return bit;
    }
};

// { Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends