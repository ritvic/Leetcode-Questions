// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:

    // int maxIndexDiff(int A[], int N) 
    // { 
    //     // Your code here
    //     int l=0,r=N-1,maxx=-1;
    //   while(l<=r){
    //       if(A[l]<=A[r]){
    //           maxx=max(maxx,r-l);
    //           l++;
    //           r=N-1;
    //       }       
    //       else{
    //           r--;
    //       }
    //   }
    //   return maxx;
    // }
    // int maxIndexDiff(int A[], int N) 
    //   { 
    //       int ans=0;
    //       stack<int> st;
    //       int i;
    //       for(i=0;i<N;i++)
    //       {
    //           if(st.empty() || A[st.top()]>A[i])
    //           {
    //               st.push(i);
    //           }
    //       }
    //       for(i=N-1;i>=0;i--)
    //       {
    //           while(!st.empty() && A[i]>=A[st.top()])
    //           {
    //               ans=max(ans,i-st.top());
    //               st.pop();
    //           }
    //       }
    //       return ans;
    //       // Your code here
    //   }
    int maxIndexDiff(int arr[], int N) 
    { 
        vector<int> lmin(N),rmax(N);
        lmin[0] = arr[0];  // storing all the minimum values from 0
        for(int i=1;i<N;i++){
            lmin[i] = min(arr[i],lmin[i-1]);
        }
        rmax[N-1] = arr[N-1]; // storing all the maximum values from N-1
        for(int i=N-2;i>=0;i--){
            rmax[i] = max(arr[i],rmax[i+1]);
        }
        
        int i=0,j=0,ans=-1;
        while(i<N and j<N){
            if(lmin[i]<=rmax[j]){
                ans = max(ans,j-i);
                j++;
            }
            else i++;
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