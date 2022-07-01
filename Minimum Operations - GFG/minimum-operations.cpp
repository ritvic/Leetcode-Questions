// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
  int dp[1000005];
  int fun(int n)
  {
      if(n==1) return dp[n]=1;
      if(dp[n]!=-1)return dp[n];
      if(n%2==0)
      return dp[n]=1+fun(n/2);
      return dp[n]=1+fun(n-1);
  }
    int minOperation(int n)
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
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends