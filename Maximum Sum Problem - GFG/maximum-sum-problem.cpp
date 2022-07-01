// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int dp[1000006];
    int fun(int n)
    {
        if(n==0 || n==1)return dp[n]=n;
        
        // if(n==2 || n==3) return dp[n]=n-1;
        if(dp[n]!=-1)return dp[n];
        
        return dp[n]=max(n,fun(n/2)+fun(n/3)+fun(n/4));
    }
        int maxSum(int n)
        {
            //code here.
            memset(dp,-1,sizeof dp);
            return fun(n);
            
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
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends