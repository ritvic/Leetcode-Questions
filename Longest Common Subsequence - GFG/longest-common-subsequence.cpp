// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence
vector<vector<int>> dp(1003,vector<int> (1003,-1));
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcss(int m, int n, string X, string Y)
    {
        // your code here
        if (m == 0 || n == 0)
        return dp[m][n]=0;
        if(dp[m][n]!=-1)
        return dp[m][n];
    if (X[m-1] == Y[n-1])
        return dp[m][n]=1 + lcss(m-1,n-1,X, Y);
    else
        return dp[m][n]=max(lcss(m,n-1,X, Y), lcss(m-1,n,X, Y));
    }
    int lcs(int m, int n, string X, string Y)
    {
        dp=vector<vector<int>>(1003,vector<int> (1003,-1));
        return lcss(m,n,X,Y);
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