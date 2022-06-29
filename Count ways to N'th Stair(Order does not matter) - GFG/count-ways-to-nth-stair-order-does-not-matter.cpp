// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int n)
    {
        // your code here
        // return 1+m/2;
        int dp[n+1];
        for(int i=0; i<=n;i++)
        dp[i]=1;
        
        for(int i=2;i<=n;i++)
        dp[i]=dp[i]+dp[i-2];
        
        return dp[n];
    }
    
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends