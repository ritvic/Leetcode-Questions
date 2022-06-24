// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        int ans=0;
       stack<int> st;
       int i;
       for(i=0;i<N;i++)
       {
           if(st.empty() || A[st.top()]>A[i])
           {
               st.push(i);
           }
       }
       for(i=N-1;i>=0;i--)
       {
           while(!st.empty() && A[i]>=A[st.top()])
           {
               ans=max(ans,i-st.top());
               st.pop();
           }
       }
       return ans;
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends