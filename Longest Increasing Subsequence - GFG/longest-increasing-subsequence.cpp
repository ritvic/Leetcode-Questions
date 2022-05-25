// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// vector<int> dp(100001,-1);
class Solution
{
    public:
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> dp(n,1);
       int ans=0;
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<i;j++)
           {
               if(a[i]>a[j])
               dp[i]=max(dp[i],1+dp[j]);
           }
           ans=max(ans,dp[i]);
       }
       return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends