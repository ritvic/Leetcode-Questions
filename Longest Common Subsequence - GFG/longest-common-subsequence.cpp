// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence
class Solution
{
    public:

    int lcs(int m, int n, string x, string y)
    {
        vector<vector<int>> dp(1003,vector<int> (1003,-1));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0 ||i==0)
                dp[i][j]=0;
                else if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];

        
    }

};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends