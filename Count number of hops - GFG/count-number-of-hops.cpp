// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int dp[100001];
    long long fun(int n)
    {
        
        // your code here
        if(n==0 || n==1) return dp[n]=1;
        if(n==2) return dp[n]=2;
        if(dp[n]!=-1) return dp[n]%1000000007;
        return dp[n]=(fun(n-1)%1000000007+fun(n-2)%1000000007+fun(n-3)%1000000007)%1000000007; 
    }
    long long countWays(int n)
    {
    memset(dp,-1,sizeof dp);
    return fun(n);
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends