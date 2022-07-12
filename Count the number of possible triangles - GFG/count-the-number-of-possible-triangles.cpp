// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible trian    gles.
    int findNumberOfTriangles(int arr[], int n)
    {
    
        sort(arr,arr+n);
        int count=0,j,k;
        for (int i=0;i<n-2;i++)
        {
            j=i+1,k=n-1;
            while (j<n-1)
            {
                while ( j<k)
                {
                    if (arr[i]+arr[j]>arr[k]){
                    count+=k-j;
                    j++;
                    k=n-1;
                }
                else  k--;
            }
            j++;
            k=n-1;}
        }
        return count ;
   // code here
   }
};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends