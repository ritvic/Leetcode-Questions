// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        int dp[n+1];
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            int count=0;
            for(int j=1;j<=2;j++)
            {
                if(j<=i)
                {
                    count+=dp[i-j]%1000000007;
                }
            }
            dp[i]=count;
        }
        return dp[n]%1000000007;
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
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
}
  // } Driver Code Ends