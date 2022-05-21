// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        
        vector<long long> dp(n+1,-1);
        const int mod=1000000007;
        dp[0]=k;
        dp[1]=k*k;
        for(int i=2;i<n;i++)
        {
            dp[i]=((dp[i-2]*(k-1))%mod+(dp[i-1]*(k-1))%mod)%mod;
        }
        return dp[n-1];
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends